/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maruzibo <maruzibo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 13:54:01 by maruzibo          #+#    #+#             */
/*   Updated: 2023/05/08 19:01:18 by maruzibo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "fractol.h"

/* fractl_pixel_color:
	Add a color to one pixel of the MLX image map.
	The MLX image is composed of 32 bits per pixel.
	Color ints are stored from right to left, here, and are in
	the form of 0xAARRGGBB. 8 bits encode each color component,
	Alpha (Transparency), Red, Green and Blue.
	Bit shifting:
		- BB >> 0   (0x000000BB)
		- GG >> 8   (0x0000GG00)
		- RR >> 16  (0x00RR0000)
		- AA >> 24  (0xAA000000)
*/
/*static void	fractl_pixel_color(t_mlx *z, int x, int y, int color)
{
		z->addr[x * 4 + y * WIDTH * 4] = color;
		z->addr[x * 4 + y * WIDTH * 4 + 1] = color >> 8;
		z->addr[x * 4 + y * WIDTH * 4 + 2] = color >> 16;
		z->addr[x * 4 + y * WIDTH * 4 + 3] = color >> 24;
}*/


void	plot_fractal(t_mlx *z)
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
    	plot_mandelbrot(z);
    else if (z-> f == 2)
    	plot_julia(z);
    else if (z-> f == 3)
    	plot_carpet(z);
    else if (z-> f == 4)
		plot_fern(z);
	/*j = -1;
	while (++j < HEIGHT)
	{
		i = -1;
		while (++i < WIDTH)
		{
			pr = z->x_min + (double)i * (z->x_min - z->x_min) / WIDTH;
			pi = z->y_min + (double)j * (z->y_min - z->y_min) / HEIGHT;
			escape = calculate_fractal(z, pr, pi);
			fractl_pixel_color(z, i, j, z->color[escape]);
		}
	}*/
	mlx_put_image_to_window(z->mlx, z->win, z->img, 0, 0);
}
