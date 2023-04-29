/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maruzibo <maruzibo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 19:25:08 by marvin            #+#    #+#             */
/*   Updated: 2023/04/29 17:02:46 by maruzibo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init(t_mlx *z)
{
	z->mlx = NULL;
	z->win = NULL;
	z->img = NULL;
	z->addr = NULL;
	z->x = 0;
	z->y = 0;
	z->x_max = 0;
	z->y_max = 0;
	z->x_min = 0;
	z->y_min = 0;
	z->cx = 0;
	z->cy = 0;
	z->color = NULL;
	z->bits_per_pixel = 0;
	z->line_length = 0;
	z->endian = 0;
}

void img_wind(t_mlx *z, char *str)
{
	z->color = ft_calloc(OMEGA + 1, sizeof(int));
	if (!z->color)
	{
		exit_husseyin(1, z);
	}
	z->mlx = mlx_init();
	z->win = mlx_new_window(z->mlx, WIDTH, HEIGHT, str);
	z->img = mlx_new_image(z->mlx, WIDTH, HEIGHT);
	z->addr = mlx_get_data_addr(z->img, &z->bits_per_pixel, &z->line_length,
			&z->endian);
	if (!z->mlx || !z->win || !z->img || !z->addr)
	{
		exit_husseyin(1, z);
	}
}
void	hooks(t_mlx *z)
{
	//mlx_key_hook(z->win, move, z);
	mlx_hook(z->win, 17, 0, exit_husseyin, z);
	//mlx_mouse_hook(z->win, zoom, p);
}

void	my_mlx_pixel_put(t_mlx *z, int i, int j, int color)
{
	char	*dst;

	dst = z->addr + (j * z->line_length + i * (z->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}
