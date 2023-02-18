/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sierp.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maruzibo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 15:39:37 by maruzibo          #+#    #+#             */
/*   Updated: 2023/02/16 13:56:14 by maruzibo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
/* Sierpinski carpet
This function returns an integer, 
where the orbit of a point falls into removed square.

We use it to dynamically color the carpet
*/
t_vec	ser(t_vec z)
{
	t_vec	r;

	r.x = 3 * z.x - floor(3 * z.x);
	r.y = 3 * z.y - floor(3 * z.y);
	return (r);
}

int	sierp(t_vec z)
{
	t_vec	next;
	double	w;
	double	e;
	int		i;

	w = 0.3333;
	e = 0.6666;
	next = z;
	i = 0;
	while (i < OMEGA)
	{
		if (next.x > w && next.x < e && next.y > w && next.y < e)
			break ;
		next = ser(next);
		i++;
	}
	return (i);
}

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
