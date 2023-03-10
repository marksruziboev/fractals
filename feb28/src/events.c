/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maruzibo <maruzibo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 13:53:34 by maruzibo          #+#    #+#             */
/*   Updated: 2023/02/28 17:59:46 by maruzibo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "fractol.h"


static void	zoom(t_fr *f, double zoom)
{
	double	cent_r, d_r;
	double	cent_i, d_i;

	cent_r = (f->max_r + f->min_r)/2;
	cent_i = (f->min_i + f->max_i)/2;
	d_r = (f->max_r - f->min_r)/2;
	d_i = (f->max_r - f->min_r)/2;
	f->max_r = cent_r + zoom * d_r;
	f->min_r = cent_r - zoom * d_r;
	f->min_i = cent_i - zoom * d_i;
	f->max_i = cent_i + zoom * d_i;
}
/* move:
*	Moves the view of the fractal by adjusting the complex
*	number edge values a certain distance in a certain direction.
*/
static void	move(t_fr *f, double distance, char direction)
{
	double	cent_r;
	double	cent_i;

	cent_r = f->max_r - f->min_r;
	cent_i = f->max_i - f->min_i;
	if (direction == 'R')
	{
		f->min_r += cent_r * distance;
		f->max_r += cent_r * distance;
	}
	else if (direction == 'L')
	{
		f->min_r -= cent_r * distance;
		f->max_r -= cent_r * distance;
	}
	else if (direction == 'D')
	{
		f->min_i -= cent_i * distance;
		f->max_i -= cent_i * distance;
	}
	else if (direction == 'U')
	{
		f->min_i += cent_i * distance;
		f->max_i += cent_i * distance;
	}
}

/* key_event_extend:
*	Handles events from the keyboard keys:
*		- 1, 2, 3, 4, 5: switch fractals
*	This function is registered to an MLX hook and will
*	automatically be called when the user does anything inside the
*	program window with the keyboard.
*	If a valid event is detected, fractltings are adjusted and the fractal
*	gets redrawn.
*/
static int	key_event_extend(int keycode, t_fr *mlx)
{
	if (keycode == KEY_ONE && mlx->fractl != MANDELBROT)
		mlx->fractl = MANDELBROT;
	else if (keycode == KEY_TWO && mlx->fractl != JULIA)
		mlx->fractl = JULIA;
	else if (keycode == KEY_THREE && mlx->fractl != CARPET)
		mlx->fractl = CARPET;
	else if (keycode == KEY_FOUR && mlx->fractl != FERN)
		mlx->fractl = FERN;
	else if (keycode == KEY_FIVE && mlx->fractl != BURNING_SHIP)
		mlx->fractl = BURNING_SHIP;
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
*	If a valid event is detected, fractltings are adjusted and the fractal
*	gets redrawn.
*/
int	key_event(int keycode, t_fr *mlx)
{
	if (keycode == KEY_ESC)
	{
		end_fractol(mlx);
		return (0);
	}
	else if (keycode == KEY_PLUS)
		zoom(mlx, 0.5);
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
*	If a valid event is detected, fractltings are adjusted and the fractal
*	gets redrawn.
*/
int	mouse_event(int keycode, int x, int y, t_fr *mlx)
{
	if (keycode == MOUSE_WHEEL_UP)
	{
		zoom(mlx, 0.5);
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
		if (mlx->fractl == JULIA)
			julia_shift(x, y, mlx);
	}
	else
		return (0);
	render(mlx);
	return (0);
}
