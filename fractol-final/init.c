/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maruzibo <maruzibo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 16:47:21 by maruzibo          #+#    #+#             */
/*   Updated: 2023/05/14 16:14:27 by maruzibo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	julia_extrmals(t_mlx *z)
{
	z->x = 0;
	z->y = 0;
	z->x_max = 2;
	z->y_max = 2;
	z->x_min = -2;
	z->y_min = -2;
	if (z->cx == 0 && z->cy == 0)
	{
		z->cx = 0.285;
		z->cy = 0.01;
	}
}

void	mandelbrot_extrmals(t_mlx *z)
{
	z->x = 0;
	z->y = 0;
	z->x_max = 2;
	z->y_max = 2;
	z->x_min = -3;
	z->y_min = -3;
}

void	carpet_extrmals(t_mlx *z)
{
	z->x = 0;
	z->y = 0;
	z->x_max = 1;
	z->y_max = 1;
	z->x_min = 0;
	z->y_min = 0;
	z->cx = 0;
	z->cy = 0;
}

void	rat_julia_extrmals(t_mlx *z)
{
	z->x = 0;
	z->y = 0;
	z->x_max = 2;
	z->y_max = 2;
	z->x_min = -2;
	z->y_min = -2;
	if (z->cx == 0 && z->cy == 0)
	{
		z->cx = 0.285;
		z->cy = 0.01;
	}
}

void	init_fractal(t_mlx *z)
{
	mlx_clear_window(z->mlx, z->win);
	if (z->f == 1)
		mandelbrot_extrmals(z);
	else if (z->f == 2)
		julia_extrmals(z);
	else if (z->f == 3)
		carpet_extrmals(z);
	else if (z->f == 4)
		rat_julia_extrmals(z);
}
