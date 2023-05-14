/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sierp.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maruzibo <maruzibo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 15:39:37 by maruzibo          #+#    #+#             */
/*   Updated: 2023/05/14 15:11:50 by maruzibo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
/* Sierpinski carpet*/
int	escape_carpet(t_mlx *z)
{
	int		i;
	double	x;
	double	y;

	i = -1;
	x = z->x;
	y = z->y;
	while (++i < 7)
	{
		if (3 * x > 1 && 3 * x < 2 && 3 * y > 1 && 3 * y < 2)
			break ;
		x = 3 * x - (int)(3 * x);
		y = 3 * y - (int)(3 * y);
	}
	return (i);
}

void	plot_carpet(t_mlx *z)
{
	int	i;
	int	j;
	int	n;

	j = -1;
	n = 0;
	while (++j < HEIGHT)
	{
		i = -1;
		z->y = z->y_max - (double)j / (double)HEIGHT;
		while (++i < WIDTH)
		{
			z->x = z->x_min + (double)i / (double)WIDTH;
			n = escape_carpet(z);
			my_mlx_pixel_put(z, i, j, n * (BLACK + 10000));
		}
	}
}
