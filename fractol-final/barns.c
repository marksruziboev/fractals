/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   barns.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maruzibo <maruzibo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 16:43:38 by maruzibo          #+#    #+#             */
/*   Updated: 2023/04/25 12:49:11 by maruzibo         ###   ########.fr       */
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
int		main(void)
{
	void	*mlx;
	void	*win;
	void	*img;

	mlx = mlx_init();
	win = mlx_new_window(mlx, WIDTH, HEIGHT, "Barnsley Fern");
	img = mlx_new_image(mlx, WIDTH, HEIGHT);

	float	p;
	long	n;
	t_ivec	i;		// this has integerd coordinates (i.x, i.y)
	t_vec		c;	// this has floating coordinates (c.x, c.y)

	c.x = 0;
	c.y = 0;

	n = 50000;
	p = 0.14; // the is the initial point for rnd(p). Thus we start with applyinf 
	while (n--)
	{
		if (p <= 0.01f)
		{
			c.x= 0;
			c.y = 0.16f * c.x; //1st map
		}
		else if (0.1f <= p && p  <= 0.86f)
		{
			c.x = 0.85 * c.x + 0.04 * c.y;
			c.y = -0.04 * c.x + 0.85 * c.y+ 1.6; // 2nd map
		}
		else if (0.86f < p && p <= 0.93f)
		{
			c.x = 0.2f * c.x + -0.26f * c.y;
			c.y = 0.23f * c.x + 0.22f * c.y + 1.6f; //3rd map
		}
		
		else if (0.93 <= p && p <= 1.0f){

			c.x = -0.15f *c.x + 0.28f * c.y;
			c.y = 0.26f *c.y + 0.24f * c.y+ 0.44f; //4th map
		}
		i.x=(c.x+3)*70;
		i.y= 800 - c.y * 70; // replace 800 with height
		mlx_pixel_put(mlx, win, (int)i.x, (int)i.y, 0x00FF00);
		p = rnd(p); 
	}
	mlx_loop(mlx);
	return (0);
}
