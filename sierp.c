/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sierp.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maruzibo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 15:39:37 by maruzibo          #+#    #+#             */
/*   Updated: 2023/02/08 15:59:06 by maruzibo         ###   ########.fr       */
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
	
	next = z;
	
	//if(z.x > 0.3333 && z.x < 0.6666 && z.y > 0.3333 && z.y < 0.6666)
	//	return (0);
	
	int i = -1;
	while(++i < 18)
	{
		
		if(next.x > 0.3333 && next.x < 0.6666 && next.y > 0.3333 && next.y < 0.6666)
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
	//t_vect c;
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
