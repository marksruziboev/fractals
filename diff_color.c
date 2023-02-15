/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maruzibo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 16:49:20 by maruzibo          #+#    #+#             */
/*   Updated: 2023/02/12 17:09:47 by maruzibo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"


t_vect ser(t_vect z)
{
	t_vect r;
		r.x = 3*z.x - floor(3*z.x);
		r.y = 3*z.y - floor(3*z.y);
	return r;
}


int ehab(t_vect z)
{
	t_vect next;
	double w = 0.3333;
	double e = 0.6666;
	next = z;
	int i = -1;
	while(++i < 6)
	{
		
		if(next.x > w && next.x < e && next.y > w && next.y < e)
		{
			return (0);
			break ;
		}
		next = ser(next);
	}
	return (1);
}

void ehabx(t_data *data, int color)
{
	t_vect z;
	t_vect next;
	
	z.x = 0;
	z.y = 0;
	
	double h = 0.001;
	
	while( z.y <= 1)
	{
		z.x = 0;
		while(z.x <= 1)
			{
				if (ehab(z) > 0)
					my_mlx_pixel_put(data, floor(600*z.x + 300), HEIGHT-floor(600*z.y+100), color);
				z.x += h;
			}
		z.y += h;
	}
}
