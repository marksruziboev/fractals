/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maruzibo <maruzibo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 16:36:29 by maruzibo          #+#    #+#             */
/*   Updated: 2023/05/05 16:58:18 by maruzibo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"


/*int	click_julia(int x, int y, t_vect *b)
{
	f->r = f->min_r + (double)x * (f->max_r - f->min_r) / WIDTH;
	f->ci = f->max_i + (double)y * (f->min_i - f->max_i) / HEIGHT;
	render(f);
	return (0);
}*/

int	escape_time(t_mlx *z)
{
	int		n;
	double	x;
	double	y;
	double	tmp;

	n = 0;
	x = z->x;
	y = z->y;
	while (n < OMEGA && (x * x + y * y < 4.0))
	{ 
		tmp = 2 * x * y + z->cy;
		x = x * x - y * y + z->cx;
		y = tmp;
		n++;
	}
	return (n);
}
void    julia_extrmals(t_mlx *z)
{
	z->title = "Julia";
	z->x = 0;
	z->y = 0;
	z->x_max = 2;
	z->y_max = 2;
	z->x_min = -2;
	z->y_min = -2;
	z->cx = 0.01;
	z->cy = 0.285;
	
	/*z->color = NULL;
	z->bits_per_pixel = 0;
	z->line_length = 0;
	z->endian = 0;*/
}


void	plot_julia(t_mlx *z)
{
	int	i;
	int	j;

	j = -1;
	julia_extrmals(z);
	//img_wind(z);
	while(++j < HEIGHT)
	{
		i = -1;
		z->y = z->y_max - (double) j * (z->y_max - z->y_min) / (double) HEIGHT;
		while(++i < WIDTH)
		{
			z->x = z->x_min + (double) i * (z->x_max - z->x_min) / (double) WIDTH;
			my_mlx_pixel_put(z, i, j, escape_time(z) * 0x0C0F00);
		}
	}
	//mlx_put_image_to_window(z->mlx, z->win, z->img, 0, 0);
}
