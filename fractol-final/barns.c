/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   barns.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maruzibo <maruzibo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 16:43:38 by maruzibo          #+#    #+#             */
/*   Updated: 2023/05/03 17:00:48 by maruzibo         ###   ########.fr       */
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
	z->title = "Barnsley Fern";
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
			z->x = 0;
			z->y = 0.16f * z->x; //1st map
		}
		else if (0.1f <= p && p  <= 0.86f)
		{
			z->x = 0.85 * z->x + 0.04 * z->y;
			z->y = -0.04 * z->x + 0.85 * z->y+ 1.6f; // 2nd map
		}
		else if (0.86f < p && p <= 0.93f)
		{
			z->x = 0.2f * z->x + -0.26f * z->y;
			z->y = 0.23f * z->x + 0.22f * z->y + 1.6f; //3rd map
		}
		else if (0.93 <= p && p <= 1.0f)
		{

			z->x = -0.15f * z->x + 0.28f * z->y;
			z->y = 0.26f * z->y + 0.24f * z->y+ 0.44f; //4th map
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
	//img_wind(z);
	while (n--)
	{
		barns(z, p);
		i = floor(z->x *70 + 170);
		/*if (i > 250)
			i = 250 - i;*/
		j = HEIGHT - floor(z->y * 42);
		my_mlx_pixel_put(z, i, j, 0x00FF00);
		p = rnd(p); 
	}
	mlx_put_image_to_window(z->mlx, z->win, z->img, 0, 0);
}
