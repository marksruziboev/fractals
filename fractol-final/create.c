/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 19:25:08 by marvin            #+#    #+#             */
/*   Updated: 2023/04/26 19:25:08 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void    init(t_mlx *w)
{
	w->mlx = NULL;
	w->win = NULL;
	w->img = NULL;
	w->addr = NULL;
    w->x = 0;
	w->y = 0;
	w->x_max = 0;
	w->y_max = 0;
	w->x_min = 0;
	w->y_min = 0;
	w->cx = 0;
	w->cy = 0;
	w->color = NULL;
	w->bits_per_pixel = 0;
	w->line_length = 0;
	w->endian = 0;
}

void    img_wind(t_mlx *z, char *str) // type mlx
{     
    z->color = ft_calloc(OMEGA + 1, sizeof(int));
    if(!z->color)
    {
		exit_husseyin(1, z);
	}
    z->mlx = mlx_init();
    if (!z->mlx)
    {
		exit_husseyin(1, z);
	}
	z->win = mlx_new_window(z->mlx, HEIGHT, HEIGHT, str);
    if (!z->win)
    {
		exit_husseyin(1, z);
	}
	z->img = mlx_new_image(z->mlx, HEIGHT, HEIGHT);
    if (!z->img)
    {
		exit_husseyin(1, z);
	}
    z->addr = mlx_get_data_addr(z->img, &(z->bits_per_pixel), &(z->line_length), &(z->endian));
    if (!z->addr)
    {
		exit_husseyin(1, z);
	}
}

void    my_mlx_pixel_put(t_mlx *z, int i, int j, int color)
{
	char	*dst;

	dst = z->addr + (j * z->line_length + i * (z->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void    plot_fractal(t_mlx *w)
{
    /*if(!ft_strncmp(ft_tolower(str), "julia", 5))
        julia(w, str);*/
    mlx_put_image_to_window(w->mlx, w->win, w->img, 0, 0);
}

