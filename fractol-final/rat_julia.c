/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rat_julia.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maruzibo <maruzibo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 16:36:29 by maruzibo          #+#    #+#             */
/*   Updated: 2023/05/14 15:13:50 by maruzibo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*
z^2 + c/z^2 = (x+iy)^2 + (x-iy)^2/(x^2+y^2) = 
(x^2 - y^2)(1 + (cx + 2xycy)/(x^2+y^2)) + i(2xy+ (cy*(x^2 - y^2)
			- 2xycx)/(x^2+y^2)) 
*/
int	escape_time_rat(t_mlx *z)
{
	int		n;
	double	x;
	double	y;
	double	tmp;
	double	tmpd;

	n = 0;
	x = z->x;
	y = z->y;
	tmpd = (x * x + y * y);
	while (n < OMEGA && (x * x + y * y < 4.0))
	{
		tmp = 2 * x * y * (1 - z->cx / (x * x + y * y)) + z->cy * (x * x - y
				* y) / (x * x + y * y);
		x = (x * x - y * y) * (1 + z->cx / (x * x + y * y)) + 2 * x * y * z->cy;
		y = tmp;
		n++;
	}
	return (n);
}

void	plot_rat_julia(t_mlx *z)
{
	int	i;
	int	j;
	int	n;

	j = -1;
	while (++j < HEIGHT)
	{
		i = -1;
		z->y = z->y_max - (double)j * (z->y_max - z->y_min) / (double)HEIGHT;
		while (++i < WIDTH)
		{
			z->x = z->x_min + (double)i * (z->x_max - z->x_min) / (double)WIDTH;
			n = escape_time_rat(z);
			my_mlx_pixel_put(z, i, j, n * (BLACK + 1000));
		}
	}
}
