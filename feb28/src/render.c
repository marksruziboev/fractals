/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maruzibo <maruzibo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 13:54:01 by maruzibo          #+#    #+#             */
/*   Updated: 2023/02/28 15:47:28 by maruzibo         ###   ########.fr       */
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
static void	fractl_pixel_color(t_fr *f, int x, int y, int color)
{
		f->buf[x * 4 + y * WIDTH * 4] = color;
		f->buf[x * 4 + y * WIDTH * 4 + 1] = color >> 8;
		f->buf[x * 4 + y * WIDTH * 4 + 2] = color >> 16;
		f->buf[x * 4 + y * WIDTH * 4 + 3] = color >> 24;
}

/* calculate_fractal:
*	Picks the correct fractal calculation function depending
*	on the current fractal fractl.
*/
static int	calculate_fractal(t_fr *f, double pr, double pi)
{
	int	nb_iter;

	if (f->fractl == MANDELBROT)
		nb_iter = mandelbrot(pr, pi);
	else if (f->fractl == JULIA)
		nb_iter = julia(f, pr, pi);
	else if (f->fractl == BURNING_SHIP)
		nb_iter = burning_ship(pr, pi);
	else if (f->fractl == TRICORN)
		nb_iter = tricorn(pr, pi);
	else if (f->fractl == MANDELBOX)
		nb_iter = mandelbox(f, pr, pi);
	return (nb_iter);
}

/* render:
*	Iterates through each pixel of the window, translates the pixel's
*	coordinates into a complex number to be able to calculate if that number
*	is part of the fractal fractl or not.
*	The number of iterations that complex number goes through before being
*	rejected from the fractal fractl determines which color is applied to the pixel.
*	Once all pixels have been assessed and added to the MLX image,
*	this function displays the MLX image to the window.
*/
void	render(t_fr *f)
{
	int		x;
	int		y;
	double	pr;
	double	pi;
	int		nb_iter;

	mlx_clear_window(f->mlx, f->win);
	y = -1;
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
		{
			pr = f->min_r + (double)x * (f->max_r - f->min_r) / WIDTH;
			pi = f->max_i + (double)y * (f->min_i - f->max_i) / HEIGHT;
			nb_iter = calculate_fractal(f, pr, pi);
			fractl_pixel_color(f, x, y, f->palette[nb_iter]);
		}
	}
	mlx_put_image_to_window(f->mlx, f->win, f->img, 0, 0);
}
