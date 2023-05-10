/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maruzibo <maruzibo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 16:47:21 by maruzibo          #+#    #+#             */
/*   Updated: 2023/05/10 18:57:10 by maruzibo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void    julia_extrmals(t_mlx *z)
{
	z->title = "Julia";
	z->x = 0;
	z->y = 0;
	z->x_max = 2;
	z->y_max = 2;
	z->x_min = -2;
	z->y_min = -2;
	if (z->cx == 0 && z-> cy == 0)
	{
		z->cx = 0.01;
		z->cy = 0.285;	
	}
	/*z->color = NULL;
	z->bits_per_pixel = 0;
	z->line_length = 0;
	z->endian = 0;*/
}
void    mandelbrot_extrmals(t_mlx *z)
{
	z->title = "Mandelbrot";
	z->x = 0;
	z->y = 0;
	z->x_max = 2;
	z->y_max = 2;
	z->x_min = -3;
	z->y_min = -3;
	//z->cx = 0;
	//z->cy = 0;
	
	/*z->color = NULL;
	z->bits_per_pixel = 0;
	z->line_length = 0;
	z->endian = 0;*/
}
void    carpet_extrmals(t_mlx *z)
{
	z->title = "Sierpinski carpet";
	z->x = 0;
	z->y = 0;
	z->x_max = 1;
	z->y_max = 1;//729;
	z->x_min = 0;
	z->y_min = 0;
	z->cx = 0;
	z->cy = 0;
}

void    fern_extrmals(t_mlx *z)
{
	z->title = "Barnsley Fern";
	z->x = 0;
	z->y = 0;
	z->x_max = 100;
	z->y_max = 100;
	z->x_min = -100;
	z->y_min = -100;
	z->cx = 0;
	z->cy = 0;
	
	/*z->color = NULL;
	z->bits_per_pixel = 0;
	z->line_length = 0;
	z->endian = 0;*/
}

void	init_fractal(t_mlx *z)
{
	/*int		i;
	int		j;
	double	pr;
	double	pi;
	int		escape;*/

	mlx_clear_window(z->mlx, z->win);
	//mlx_destroy_display(z->mlx);
	//mlx_destroy_image(z->mlx, z->img);
	//init(z);
	if (z-> f == 1)
    	mandelbrot_extrmals(z);
    else if (z-> f == 2)
    	julia_extrmals(z);
    else if (z-> f == 3)
    	carpet_extrmals(z);
    else if (z-> f == 4)
		fern_extrmals(z);
}