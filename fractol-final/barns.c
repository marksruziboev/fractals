/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   barns.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maruzibo <maruzibo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 16:43:38 by maruzibo          #+#    #+#             */
/*   Updated: 2023/04/29 19:29:40 by maruzibo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
/*#include <stdlib.h>
//#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdio.h>*/


double rnd(double x)
{
	if (0 < x && x < 0.1)
		return(10*x);
	else if (0.1 < x && x < 0.86)
		return(1.315789*x - 0.131578);
	else if (0.86 < x && x < 0.93)
		return(14.285714*x - 12.285714);
	else if (0.93 < x && x < 1)
		return(14.285714*x - 13.285714);
	else 
		return (0.09f*fabs(x));
}
void    fern_extrmals(t_mlx *z)
{
	z->x = 0;
	z->y = 0;
	z->x_max = 100;
	z->y_max = 800;
	z->x_min = -800;
	z->y_min = -800;
	z->cx = 0;
	z->cy = 0;
	
	/*z->color = NULL;
	z->bits_per_pixel = 0;
	z->line_length = 0;
	z->endian = 0;*/
}

void barns(t_mlx *z, float	p)
{
	if (p <= 0.01f)
		{
			z->cx = 0;
			z->cy = 0.16f * z->cx; //1st map
		}
		else if (0.1f <= p && p  <= 0.86f)
		{
			z->cx = 0.85 * z->cx + 0.04 * z->cy;
			z->cy = -0.04 * z->cx + 0.85 * z->cy+ 1.6f; // 2nd map
		}
		else if (0.86f < p && p <= 0.93f)
		{
			z->cx = 0.2f * z->cx + -0.26f * z->cy;
			z->cy = 0.23f * z->cx + 0.22f * z->cy + 1.6f; //3rd map
		}
		else if (0.93 <= p && p <= 1.0f)
		{

			z->cx = -0.15f * z->cx + 0.28f * z->cy;
			z->cy = 0.26f * z->cy + 0.24f * z->cy+ 0.44f; //4th map
		}
}
void	plot_fern(t_mlx *z)
{
	float	p;
	int	n;
	int i;
	int	j;

	n = 500000;
	p = 0.14; // the is the initial point for rnd(p). Thus we start with applyinf 
	fern_extrmals(z);
	while (n--)
	{
		barns(z, p);
		i = floor(z->cx *70 + 170);
		/*if (i > 250)
			i = 250 - i;*/
		j = HEIGHT - floor(z->cy * 42);
		my_mlx_pixel_put(z, i, j, 0x00FF00);
		//my_mlx_pixel_put(z, i, j, escape_time(z) * 0x0C0F00);
		p = rnd(p); 
	}
	mlx_put_image_to_window(z->mlx, z->win, z->img, 0, 0);
}
