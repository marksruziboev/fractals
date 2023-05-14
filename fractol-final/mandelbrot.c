/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maruzibo <maruzibo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 15:44:22 by maruzibo          #+#    #+#             */
/*   Updated: 2023/05/14 16:15:19 by maruzibo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	plot_mandelbrot(t_mlx *z)
{
	int	i;
	int	j;
	int	n;

	j = -1;
	while (++j < HEIGHT)
	{
		i = -1;
		z->cy = z->y_max - (double)j * (z->y_max - z->y_min) / (double)HEIGHT;
		while (++i < WIDTH)
		{
			z->cx = z->x_min + (double)i * (z->x_max - z->x_min)
				/ (double)WIDTH;
			n = escape_time(z);
			my_mlx_pixel_put(z, i, j, n * (BLACK + 10000));
		}
	}
}
