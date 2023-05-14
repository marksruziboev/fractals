/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maruzibo <maruzibo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 16:36:29 by maruzibo          #+#    #+#             */
/*   Updated: 2023/05/14 15:14:30 by maruzibo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	click_julia(t_mlx *z, int i, int j)
{
	z->cx = z->cx + (double)(i - WIDTH / 2) / WIDTH;
	z->cy = z->cy + (double)(j - HEIGHT / 2) / HEIGHT;
	plot_fractal(z);
	return (0);
}

int	escape_time(t_mlx *z)
{
	int		n;
	double	x;
	double	y;
	double	tmp;

	n = 0;
	x = z->x;
	y = z->y;
	while (n < OMEGA && (x * x + y * y < 4.0))
	{
		tmp = 2 * x * y + z->cy;
		x = x * x - y * y + z->cx;
		y = tmp;
		n++;
	}
	return (n);
}

void	plot_julia(t_mlx *z)
{
	int	i;
	int	j;
	int	n;

	n = 0;
	j = -1;
	while (++j < HEIGHT)
	{
		i = -1;
		z->y = z->y_max - (double)j * (z->y_max - z->y_min) / (double)HEIGHT;
		while (++i < WIDTH)
		{
			z->x = z->x_min + (double)i * (z->x_max - z->x_min) / (double)WIDTH;
			n = escape_time(z);
			my_mlx_pixel_put(z, i, j, n * (BLACK + 1000));
		}
	}
}
