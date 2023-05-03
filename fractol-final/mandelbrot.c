/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maruzibo <maruzibo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 15:44:22 by maruzibo          #+#    #+#             */
/*   Updated: 2023/05/03 17:00:55 by maruzibo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/* mandelbrot:
*   This functions checks whether a complex number is in the Mandelbrot set or not.
*   for z \in C we look at |z|.
*   Returns the number of iterations before the number escapes 
*   the Mandelbrot set, which can then be used to determine coloring.
*/
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

void	plot_mandelbrot(t_mlx *z)
{
	int	i;
	int	j;

	j = -1;
	mandelbrot_extrmals(z);
	//img_wind(z);
	while(++j < HEIGHT)
	{
		i = -1;
		z->cy = z->y_max - (double) j * (z->y_max - z->y_min)/(double) HEIGHT;
		while(++i < WIDTH)
		{
			z->cx = z->x_min + (double) i * (z->x_max - z->x_min) / (double) WIDTH;
			my_mlx_pixel_put(z, i, j, escape_time(z) * 0x0C0F00);
		}
	}
	mlx_put_image_to_window(z->mlx, z->win, z->img, 0, 0);
}
