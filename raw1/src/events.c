/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maruzibo <maruzibo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 16:18:56 by mcombeau          #+#    #+#             */
/*   Updated: 2023/02/19 16:38:58 by maruzibo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/* zoom:
*	Zooms the view of the fractal in or out by adjusting
*	the complex number edge values by a zoom multiplier.
*	The fractal can then be generated again at a different resolution,
*	giving the appearance of zooming in or out.
*	If the zoom multiplier is small, like 0.5, the view will
*	zoom in, if it is big, like 2.0, it will zoom out.
*/

static void	zoom(t_f *f, double zoom)
{
	double	cntr_r, d_r;
	double	cntr_i, d_i;

	cntr_r = (f->max_r + f->min_r)/2;
	cntr_i = (f->min_i + f->max_i)/2;
	d_r = (f->max_r - f->min_r)/2;
	d_i = (f->max_r - f->min_r)/2;
	f->max_r = cntr_r + zoom * d_r;
	f->min_r = cntr_r - zoom * d_r;
	f->min_i = cntr_i - zoom * d_i;
	f->max_i = cntr_i + zoom * d_i;
}
/* move:
*	Moves the view of the fractal by adjusting the complex
*	number edge values a certain dist in a certain dir.
*/
static void	move(t_f *f, double dist, char dir)
{
	double	cntr_r;
	double	cntr_i;

	cntr_r = f->max_r - f->min_r;
	cntr_i = f->max_i - f->min_i;
	if (dir == 'R')
	{
		f->min_r += cntr_r * dist;
		f->max_r += cntr_r * dist;
	}
	else if (dir == 'L')
	{
		f->min_r -= cntr_r * dist;
		f->max_r -= cntr_r * dist;
	}
	else if (dir == 'D')
	{
		f->min_i -= cntr_i * dist;
		f->max_i -= cntr_i * dist;
	}
	else if (dir == 'U')
	{
		f->min_i += cntr_i * dist;
		f->max_i += cntr_i * dist;
	}
}

/* key_event_extend:
*	Handles events from the keyboard keys:
*		- 1, 2, 3, 4, 5: switch fractals
*	This function is registered to an MLX hook and will
*	automatically be called when the user does anything inside the
*	program window with the keyboard.
*	If a valid event is detected, settings are adjusted and the fractal
*	gets redrawn.
*/
static int	key_event_extend(int keycode, t_f *mlx)
{
	if (keycode == KEY_ONE && mlx->set != MANDELBROT)
		mlx->set = MANDELBROT;
	else if (keycode == KEY_TWO && mlx->set != JULIA)
		mlx->set = JULIA;
	else if (keycode == KEY_THREE && mlx->set != BURNING_SHIP)
		mlx->set = BURNING_SHIP;
	else if (keycode == KEY_FOUR && mlx->set != TRICORN)
		mlx->set = TRICORN;
	else if (keycode == KEY_FIVE && mlx->set != MANDELBOX)
		mlx->set = MANDELBOX;
	else
		return (1);
	get_complex_layout(mlx);
	render(mlx);
	return (0);
}

/* key_event:
*	Handles events from the keyboard keys:
*		- + or - key: zoom
*		- Arrow keys or WASD: move
*		- Space: color shift
*	This function is registered to an MLX hook and will
*	automatically be called when the user does anything inside the
*	program window with the keyboard.
*	If a valid event is detected, settings are adjusted and the fractal
*	gets redrawn.
*/
int	key_event(int keycode, t_f *mlx)
{
	if (keycode == KEY_ESC)
	{
		end_fractol(mlx);
		return (0);
	}
	else if (keycode == KEY_PLUS)
		zoom(mlx, 0.1);
	else if (keycode == KEY_MINUS)
		zoom(mlx, 2);
	else if (keycode == KEY_UP || keycode == KEY_W)
		move(mlx, 0.2, 'U');
	else if (keycode == KEY_DOWN || keycode == KEY_S)
		move(mlx, 0.2, 'D');
	else if (keycode == KEY_LEFT || keycode == KEY_A)
		move(mlx, 0.2, 'L');
	else if (keycode == KEY_RIGHT || keycode == KEY_D)
		move(mlx, 0.2, 'R');
	else if (keycode == KEY_SPACE)
		color_shift(mlx);
	else if (!key_event_extend(keycode, mlx))
		return (1);
	else
		return (1);
	render(mlx);
	return (0);
}

/* mouse_event:
*	Handles events from the mouse:
*		- Mouse wheel: zoom
*		- Left click: Julia shift
*	This function is registered to an MLX hook and will
*	automatically be called when the user does anything inside the
*	program window with the mouse.
*	If a valid event is detected, settings are adjusted and the fractal
*	gets redrawn.
*/
int	mouse_event(int keycode, int x, int y, t_f *mlx)
{
	if (keycode == MOUSE_WHEEL_UP)
	{
		zoom(mlx, 0.8);
		x -= WIDTH / 2;
		y -= HEIGHT / 2;
		if (x < 0)
			move(mlx, (double)x * -1 / WIDTH, 'L');
		else if (x > 0)
			move(mlx, (double)x / WIDTH, 'R');
		if (y < 0)
			move(mlx, (double)y * -1 / HEIGHT, 'U');
		else if (y > 0)
			move (mlx, (double)y / HEIGHT, 'D');
	}
	else if (keycode == MOUSE_WHEEL_DOWN)
		zoom(mlx, 2);
	else if (keycode == MOUSE_BTN)
	{
		if (mlx->set == JULIA)
			julia_shift(x, y, mlx);
	}
	else
		return (0);
	render(mlx);
	return (0);
}
