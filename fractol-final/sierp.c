/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sierp.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maruzibo <maruzibo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 15:39:37 by maruzibo          #+#    #+#             */
/*   Updated: 2023/04/28 17:50:13 by maruzibo         ###   ########.fr       */
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
	int	r;
	int	w;

	w = 729;
	if(x >= 0 && x <  w / 3)
		return(3 * x);
	else if (x >= w / 3 && x < 2 * w / 3)
		return(3 * x - w);
	else if (x >= 2 * w / 3 && x < w)
		return(3 * x - 2 * w);
}

int	sierp(t_mlx *z)
{
	int	w;
	
	w = 729;
	if (map(i) > w / 3	&& map(i) < 2 * w / 2 && map(j) > w / 3	&& map(j) < 2 * w / 2)
	
	
}

/*int something(t_mlx *z)	
{
	double	e;
	int		i;

	w = 729;

	next = z;
	i = 0;
	while (i < OMEGA)
	{
		if (next.x > w && next.x < e && next.y > w && next.y < e)
			return (i);
		next = ser(next);
		i++;
	}
	return (i);
}
*/
/*void	sierpp(t_data *data, int color)
{
	t_vect	z;
	t_vect	next;
	double	h;

	z.x = 0;
	z.y = 0;
	h = 0.001;
	while (z.y <= 1)
	{
		z.x = 0;
		while (z.x <= 1)
		{
			if (sierp(z) > 0)
				my_mlx_pixel_put(data, floor(600 * z.x + 300), HEIGHT - floor(600 * z.y + 100), color);
			z.x += h;
		}
		z.y += h;
	}
}*/
