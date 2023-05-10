/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maruzibo <maruzibo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 11:26:41 by maruzibo          #+#    #+#             */
/*   Updated: 2023/05/10 18:54:32 by maruzibo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/* zoom:
*	If the zoom multiplier is small, like 0.5, the view will
*	zoom in, if it is big, like 2.0, it will zoom out.
*/
/*static void	ft_zoom(t_mlx *z, double v, int mouse_x, int mouse_y)
{
	double center_x = (z->x_min + z->x_max) / 2;
	double center_y = (z->y_min + z->y_max) / 2;
	double dx = (z->x_max - z->x_min) / 2;
	double dy = (z->y_max - z->y_min) / 2;
	double mouse_dx = (mouse_x - WIDTH / 2) / (double)WIDTH;
	double mouse_dy = (mouse_y - HEIGHT / 2) / (double)HEIGHT;
	double zoom_dx = dx * v;
	double zoom_dy = dy * v;
	
	z->x_min = center_x - (dx + mouse_dx * dx - zoom_dx);
	z->x_max = center_x + (dx - mouse_dx * dx - zoom_dx);
	z->y_min = center_y - (dy + mouse_dy * dy - zoom_dy);
	z->y_max = center_y + (dy - mouse_dy * dy - zoom_dy);
	
	plot_fractal(z);
}*/
static void	ft_zoom(t_mlx *z, double zoom)
{
	/*double	wid = z->x_max - z->x_min;
	double	hig = z->y_max - z->y_min;
	double	centx = z->x_min + wid / 2;
	double	centy = z->y_min - hig / 2;

	z->x_min = z->x_min + v * wid / 2;
	z->x_max = z->x_max - v * wid / 2;
	z->y_min = z->y_min + v * hig / 2;
	z->y_max = z->y_max - v * hig / 2;*/
	

	double	center_r;
	double	center_i;

	center_r = z->x_min - z->x_max;
	center_i = z->y_max - z->y_min;
	z->x_max = z->x_max + (center_r - zoom * center_r) / 2;
	z->x_min = z->x_max + zoom * center_r;
	z->y_min = z->y_min + (center_i - zoom * center_i) / 2;
	z->y_max = z->y_min + zoom * center_i;
}
/*
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
	//plot_fractal(z);
}*/

/* move:
*	This function moves the fractal by adjusting in the direction dirct to a distance dst
*/
static void	ft_move(t_mlx *z, double dst, char dirct)
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
	else if (dirct == 'U')
	{
		z->y_min += dy * dst;
		z->y_max += dy * dst;
	}
	else if (dirct == 'D')
	{
		z->y_min -= dy * dst;
		z->y_max -= dy * dst;
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
		ft_zoom(z, 0.5);//, WIDTH/2, HEIGHT/2);
	else if (keycode == KEY_MINUS)
		ft_zoom(z, 2);// WIDTH/2, HEIGHT/2);
	else if (keycode == KEY_UP)
		ft_move(z, 0.5, 'U');
	else if (keycode == KEY_DOWN)
		ft_move(z, 0.5, 'D');
	else if (keycode == KEY_LEFT)
		ft_move(z, 0.5, 'L');
	else if (keycode == KEY_RIGHT)
		ft_move(z, 0.5, 'R');
	/*else if (keycode == KEY_ENTER)
		shift_color_range(z);*/
	else
		return (1);
	plot_fractal(z);
	return (0);
}

/* mouse_events:
*		- Mouse wheel: zoom
*		- Left click: Julia shift
*/
int	mouse_event(int keycode, int i, int j, t_mlx *z)//
{
	if (keycode == MOUSE_WHEEL_UP)
	{
		mlx_mouse_get_pos(z->mlx, z->win, &i, &j);
		ft_zoom(z, 0.5);//, i, j);
		i -= WIDTH / 2;
		j -= HEIGHT / 2;
		if (i < 0)
			ft_move(z, (double)i * -1 / WIDTH, 'L');
		else if (i > 0)
			ft_move(z, (double)j / WIDTH, 'R');
		if (j < 0)
			ft_move(z, (double)j * -1 / HEIGHT, 'U');
		else if (j > 0)
			ft_move (z, (double)j / HEIGHT, 'D');
	}
	else if (keycode == MOUSE_WHEEL_DOWN)
		ft_zoom(z, 2);//, i, j);
	else if (keycode == MOUSE_BTN)
	{
		if (z->f == 2)
			click_julia(z, i, j);
	}
	else
		return (0);
	plot_fractal(z);
	return (0);
}
