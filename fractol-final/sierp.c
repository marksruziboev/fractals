/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sierp.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maruzibo <maruzibo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 15:39:37 by maruzibo          #+#    #+#             */
/*   Updated: 2023/05/10 17:20:06 by maruzibo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
/* Sierpinski carpet
This function returns an integer, 
where the orbit of a point falls into removed square.

We use it to dynamically color the carpet
*/
int	map(int x)
{
	int	w;

	w = 729;
	if(x >= 0 && 3 * x <  w)
		return(3 * x);
	else if (3 * x >= w  && 3 * x < 2 * w)
		return(3 * x - w);
	else //(x >= 2 * w / 3 && x < w)
		return(3 * x - 2 * w);
}

int	escape_carpet(t_mlx *z)
{
	int	w;
	int	x;
	int	y;
	int i;
	
	w = 729;
	i = -1;
	x = w*(int)z->x;
	y = w*(int)z->y;
	while (++i < OMEGA)
	{
		if ((3 * x > w 	&& 3 * x < 2 * w) && (3 * y > w	&& 3 * y < 2 * w))
			break;
		x = map(x);
		y = map(y);
	}
	return (i);
}


void	plot_carpet(t_mlx *z)
{
	int	i;
	int	j;

	//carpet_extrmals(z);
	//img_wind(z);
	j = -1;
	while(++j <= HEIGHT)
	{
		i = -1;
		z->y = (double) j;
		while(++i <= WIDTH)
		{
			z->x = (double) i;
			my_mlx_pixel_put(z, i, j, (escape_carpet(z) + 1) * 0x0000F0F);
		}
	}
	mlx_put_image_to_window(z->mlx, z->win, z->img, 0, 0);
}
