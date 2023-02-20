/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   barns.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maruzibo <maruzibo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 16:43:38 by maruzibo          #+#    #+#             */
/*   Updated: 2023/02/19 19:01:46 by maruzibo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/fractol.h"
#include <stdlib.h>
//#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdio.h>


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
int		fern(t_f *f, double cx, double cy)
{
	/*void	*mlx;
	void	*win;
	void	*img;

	mlx = mlx_init();
	win = mlx_new_window(mlx, 900, 800, "Barnsley Fern");
	img = mlx_new_image(mlx, WIDTH, HEIGHT);
*/
	float	p;
	long	n;
	//t_ivec	i;		// this has integer coordinates (i.x, i.y)
	//t_vec		c;	// this has floating coordinates (cx, cy)

	cx = 0;
	cy = 0;

	n = 50000;
	p = 0.14; // the is the initial point for rnd(p). Thus we start with applyinf 
	while (n--)
	{
		if (p <= 0.01f)
		{
			cx= 0;
			cy = 0.16f * cx; //1st map
		}
		else if (0.1f <= p && p  <= 0.86f)
		{
			cx = 0.85 * cx + 0.04 * cy;
			cy = -0.04 * cx + 0.85 * cy+ 1.6; // 2nd map
		}
		else if (0.86f < p && p <= 0.93f)
		{
			cx = 0.2f * cx + -0.26f * cy;
			cy = 0.23f * cx + 0.22f * cy + 1.6f; //3rd map
		}
		
		else if (0.93 <= p && p <= 1.0f){

			cx = -0.15f *cx + 0.28f * cy;
			cy = 0.26f *cy + 0.24f * cy+ 0.44f; //4th map
		}
		//i.x=(cx+3)*70;
		//i.y= 800 - cy * 70; // replace 800 with height
		mlx_pixel_put(mlx, win, (int)i.x, (int)i.y, 0x00FF00);
		p = rnd(p); 
	}
	return(n);
	//mlx_loop(mlx);
	//return (0);
}
