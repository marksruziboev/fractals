/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maruzibo <maruzibo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 11:26:41 by maruzibo          #+#    #+#             */
/*   Updated: 2023/05/05 17:32:23 by maruzibo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/* zoom:
*	If the zoom multiplier is small, like 0.5, the view will
*	zoom in, if it is big, like 2.0, it will zoom out.
*/
static void	ft_zoom(t_mlx *z, double v)
{
	double	dx;
	double	dy;

	dx = (z->x_max - z->x_min)/2;
	dy = (z->y_max - z->y_min)/2;
	z->x_max = dx - (1 - v) * dx;
	z->x_min = dx + (1 - v) * dx;
	z->y_min = dy - (1 - v) * dy; 
	z->y_max = dy + (1 - v) * dx;
}

/* move:
*	This function moves the fractal by adjusting in the direction dirct to a distance dst
*/
static void	move(t_mlx *z, double dst, char dirct)
{
	double	dx;
	double	dy;

	dx = z->x_max - z->x_min;
	dy = z->y_max - z->y_min;
	if (dirct == 'R')
	{
		z->x_min += dx * dst;
		z->x_max += dx * dst;
	}
	else if (dirct == 'L')
	{
		z->x_min -= dx * dst;
		z->x_max -= dx * dst;
	}
	else if (dirct == 'D')
	{
		z->y_min -= dy * dst;
		z->y_max -= dy * dst;
	}
	else if (dirct == 'U')
	{
		z->y_min += dy * dst;
		z->y_max += dy * dst;
	}
}

/* key_event:
*	Handles events from the keyboard keys:
*		- + or - key: zoom
*		- Arrow keys or WASD: move
*		- Space: color shift
*/
int	key_pr(int keycode, t_mlx *z)
{
	if (keycode == KEY_ESC)
	{
		exit_husseyin(0, z);
		return (0);
	}
	else if (keycode == KEY_PLUS)
		zoom(z, 0.5);
	else if (keycode == KEY_MINUS)
		zoom(z, 2);
	else if (keycode == KEY_UP || keycode == KEY_W)
		move(z, 0.3, 'up');
	else if (keycode == KEY_DOWN || keycode == KEY_S)
		move(z, 0.3, 'down');
	else if (keycode == KEY_LEFT || keycode == KEY_A)
		move(z, 0.3, 'left');
	else if (keycode == KEY_RIGHT || keycode == KEY_D)
		move(z, 0.3, 'right');
	else if (keycode == KEY_ENTER)
		shift_color_range(z);
	else
		return (1);
	render(z);
	return (0);
}

/* mouse_events:
*		- Mouse wheel: zoom
*		- Left click: Julia shift
*/
int	mouse_event(int keycode, int i, int j, t_mlx *z)
{
	if (keycode == MOUSE_WHEEL_UP)
	{
		zoom(z, 0.5);
		i -= WIDTH / 2;
		j -= HEIGHT / 2;
		if (i < 0)
			move(z, (double)i * -1 / WIDTH, 'left');
		else if (i > 0)
			move(z, (double)j / WIDTH, 'right');
		if (j < 0)
			move(z, (double)j * -1 / HEIGHT, 'up');
		else if (j > 0)
			move (z, (double)j / HEIGHT, 'down');
	}
	else if (keycode == MOUSE_WHEEL_DOWN)
		zoom(z, 2);
	/*else if (keycode == MOUSE_BTN)
	{
		if (z->set == 2)
			julia_shift(x, y, mlx);
	}*/
	else
		return (0);
	//render(mlx);
	return (0);
}
