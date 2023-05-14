/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maruzibo <maruzibo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 11:26:41 by maruzibo          #+#    #+#             */
/*   Updated: 2023/05/14 16:50:15 by maruzibo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	ft_zoom(t_mlx *z, double v)
{
	double	wid;
	double	hig;

	wid = z->x_max - z->x_min;
	hig = z->y_max - z->y_min;
	z->x_max = z->x_max - (1 - v) * wid / 2;
	z->x_min = z->x_max - v * wid;
	z->y_min = z->y_min + (1 - v) * hig / 2;
	z->y_max = z->y_min + v * hig;
}

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
*		- Arrow keys: move
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
		ft_zoom(z, 0.6);
	else if (keycode == KEY_MINUS)
		ft_zoom(z, 1.7);
	else if (keycode == KEY_UP)
		ft_move(z, 0.25, 'U');
	else if (keycode == KEY_DOWN)
		ft_move(z, 0.25, 'D');
	else if (keycode == KEY_LEFT)
		ft_move(z, 0.25, 'L');
	else if (keycode == KEY_RIGHT)
		ft_move(z, 0.25, 'R');
	else
		return (1);
	plot_fractal(z);
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
		ft_zoom(z, 0.5);
		i -= WIDTH / 2;
		j -= HEIGHT / 2;
		if (i < 0)
			ft_move(z, -1 * (double)i / WIDTH, 'L');
		else if (i > 0)
			ft_move(z, (double)j / WIDTH, 'R');
		if (j < 0)
			ft_move(z, (double)j * -1 / HEIGHT, 'U');
		else if (j > 0)
			ft_move(z, (double)j / HEIGHT, 'D');
	}
	else if (keycode == MOUSE_WHEEL_DOWN)
		ft_zoom(z, 2);
	else if (keycode == MOUSE_BTN)
	{
		if (z->f == 2 || z->f == 4)
			click_julia(z, i, j);
	}
	else
		return (0);
	plot_fractal(z);
	return (0);
}

/*int mouse_event(int keycode, int mouse_x, int mouse_y, t_mlx *z)
{
    double v = 0.5; // Zoom factor

	mlx_mouse_get_pos(z->mlx, z->win, &mouse_x, &mouse_y);

    if (keycode == MOUSE_WHEEL_UP)
    {
        // Calculate the normalized mouse position within the window
        double norm_x = (double)mouse_x / WIDTH;
        double norm_y = (double)mouse_y / HEIGHT;

        // Calculate the difference between the current zoom and the new zoom
        double diff_x = z->x_max - z->x_min;
        double diff_y = z->y_max - z->y_min;
        double new_diff_x = diff_x * v;
        double new_diff_y = diff_y * v;
        double diff_diff_x = diff_x - new_diff_x;
        double diff_diff_y = diff_y - new_diff_y;

        // Update the zoom
        z->x_min += diff_diff_x * norm_x;
        z->x_max -= diff_diff_x * (1 - norm_x);
        z->y_min += diff_diff_y * norm_y;
        z->y_max -= diff_diff_y * (1 - norm_y);

        // Adjust the position of the fractal based on the mouse cursor
        double offset_x = (double)mouse_x / WIDTH * diff_diff_x;
        double offset_y = (double)mouse_y / HEIGHT * diff_diff_y;
        ft_move(z, offset_x, offset_y);
    }
    else if (keycode == MOUSE_WHEEL_DOWN)
    {
        // Perform the zoom out
        ft_zoom(z, 2);

        // Adjust the position of the fractal based on the mouse cursor
        double offset_x = (double)mouse_x / WIDTH * (z->x_max - z->x_min);
        double offset_y = (double)mouse_y / HEIGHT * (z->y_max - z->y_min);
        ft_move(z, offset_x, offset_y);
    }
    else if (keycode == MOUSE_BTN)
    {
        // Handle mouse button event
        if (z->f == 2 || z->f == 4)
            click_julia(z, mouse_x, mouse_y);
    }
    else
    {
        return 0;
    }

    plot_fractal(z);
    return 0;
}*/

