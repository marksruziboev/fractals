/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maruzibo <maruzibo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 13:53:52 by maruzibo          #+#    #+#             */
/*   Updated: 2023/02/28 18:45:17 by maruzibo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "fractol.h"

/* clean_init:
*	Initializes the fractol data structure with default
*	values to be replaced later. Used for error detection.
*/
void	clean_init(t_fr *f)
{
	f->mlx = NULL;
	f->win = NULL;
	f->img = NULL;
	f->data = NULL;
	f->fractl = -1;
	f->min_r = 0;
	f->max_r = 0;
	f->min_i = 0;
	f->max_i = 0;
	f->hr = 0;
	f->hi = 0;
	f->sx = 0;
	f->rx = 0;
	f->fx = 0;
	f->col_arr = NULL;
	f->color_pattern = -1;
	f->color = 0;
}

/* get_complex_layout:
*	Maps the complex number axes to the window width and height to
*	create an equivalence between a given pixel and a complex number.
*		- The Mandelbox fractl real and imaginary axes range from 4 to -4
*		so the edges are mapped to those numbers for the fractal to appear
*		centered.
*		- Julia needs a bit more space to the right than Mandelbrot or
*		Burning Ship, so the mapping must also be shifted slightly.
*	Also, one of the edges is always calculated according to the other edges
*	to avoid fractal distortion if the window proportions change.
*/
void	get_complex_layout(t_fr *f)
{
	if (f->fractl == MANDELBROT)
	{
		f->min_r = -4.0;
		f->max_r = 4.0;
		f->min_i = -4.0;
		f->max_i = f->min_i + (f->max_r - f->min_r) * HEIGHT / WIDTH;
	}
	else if (f->fractl == JULIA)
	{
		f->min_r = -2.0;
		f->max_r = 2.0;
		f->min_i = -2.0;
		f->max_i = f->min_i + (f->max_r - f->min_r) * HEIGHT / WIDTH;
	}
	else if (f->fractl == FERN)
	{
		f->min_r = -100;
		f->max_r = 100;
		f->min_i = 100;
		f->max_i = f->min_i + (f->max_r - f->min_r) * HEIGHT / WIDTH;
	}
	else if (f->fractl == CARPET)
	{
		f->min_r = 0.1;
		f->max_r = 1.1;
		f->min_i = 0.1;
		f->max_i = f->min_i + (f->max_r - f->min_r) * HEIGHT / WIDTH;
	}
	else
	{
		f->min_r = -2.0;
		f->max_r = 1.0;
		f->max_i = -1.5;
		f->min_i = f->max_i + (f->max_r - f->min_r) * HEIGHT / WIDTH;
	}
	
}

/* init_img:
*	Initializes an MLX image and a color col_arr. The color col_arr will
*	be used to store every shade of color for every iteration number,
*	and the color of each pixel will be stored in the image, which will
*	then be displayed in the program window.
*/
static void	init_img(t_fr *f)
{
	int		pixel_bits;
	int		line_bytes;
	int		endian;
	char	*data;

	f->col_arr = ft_calloc((MAX_ITERATIONS + 1), sizeof(int));
	if (!(f->col_arr))
		clean_exit(msg("error initializing color scheme.", "", 1), f);
	f->img = mlx_new_image(f->mlx, WIDTH, HEIGHT);
	if (!(f->img))
		clean_exit(msg("Was not able to create image.", "", 1), f);
	data = mlx_get_data_addr(f->img, &pixel_bits, &line_bytes, &endian);
	f->data = data;
}

/* reinit_image:
*	Cleanly reinitializes the MLX image if the color col_arr or 
*	fractal type is modified at runtime.
*/
void	reinit_img(t_fr *f)
{
	if (f->mlx && f->img)
		mlx_destroy_image(f->mlx, f->img);
	if (f->col_arr)
		free(f->col_arr);
	if (f->data)
		f->data = NULL;
	init_img(f);
}

/* init:
*	Creates a new MLX instance, a new window and populates
*	the fractol data structure with default values.
*/
void	init(t_fr *f)
{
	f->mlx = mlx_init();
	if (!f->mlx)
		clean_exit(msg("MLX: error connecting to mlx.", "", 1), f);
	f->win = mlx_new_window(f->mlx, WIDTH, HEIGHT, "Fractol");
	if (!f->win)
		clean_exit(msg("MLX: error creating window.", "", 1), f);
	f->sx = 2.0;
	f->rx = 0.5;
	f->fx = 1.0;
	get_complex_layout(f);
	color_shift(f);
}
