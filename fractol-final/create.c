/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maruzibo <maruzibo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 19:25:08 by marvin            #+#    #+#             */
/*   Updated: 2023/05/14 16:02:45 by maruzibo         ###   ########.fr       */
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
	z->bits_per_pixel = 0;
	z->line_length = 0;
	z->endian = 0;
}

void	img_wind(t_mlx *z)
{
	z->mlx = mlx_init();
	z->win = mlx_new_window(z->mlx, WIDTH, HEIGHT, "Fractal");
	z->img = mlx_new_image(z->mlx, WIDTH, HEIGHT);
	z->addr = mlx_get_data_addr(z->img, &z->bits_per_pixel, &z->line_length,
			&z->endian);
	if (!z->mlx || !z->win || !z->img || !z->addr)
	{
		exit_husseyin(1, z);
	}
}

int	mouse_close(t_mlx *z)
{
	exit_husseyin(1, z);
	return (0);
}

void	hooks(t_mlx *z)
{
	mlx_key_hook(z->win, &key_pr, z);
	mlx_hook(z->win, 2, 1L << 0, key_pr, z);
	mlx_hook(z->win, 17, 1L << 17, &mouse_close, z);
	mlx_mouse_hook(z->win, &mouse_event, z);
}

void	my_mlx_pixel_put(t_mlx *z, int i, int j, int color)
{
	char	*dst;

	dst = z->addr + (j * z->line_length + i * (z->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}
