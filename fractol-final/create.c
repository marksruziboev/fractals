/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maruzibo <maruzibo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 19:25:08 by marvin            #+#    #+#             */
/*   Updated: 2023/05/03 18:03:15 by maruzibo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init(t_mlx *z)
{
	z->mlx = NULL;
	z->win = NULL;
	z->img = NULL;
	z->addr = NULL;
	z->title = NULL;
	z->x = 0;
	z->y = 0;
	z->x_max = 0;
	z->y_max = 0;
	z->x_min = 0;
	z->y_min = 0;
	z->cx = 0;
	z->cy = 0;
	//z->color = NULL;
	z->bits_per_pixel = 0;
	z->line_length = 0;
	z->endian = 0;
}

void img_wind(t_mlx *z)
{
	/*z->color = ft_calloc(OMEGA + 1, sizeof(int));
	if (!z->color)
	{
		exit_husseyin(1, z);
	}*/
	z->mlx = mlx_init();
	z->win = mlx_new_window(z->mlx, WIDTH, HEIGHT, z->title);
	z->img = mlx_new_image(z->mlx, WIDTH, HEIGHT);
	z->addr = mlx_get_data_addr(z->img, &z->bits_per_pixel, &z->line_length,
			&z->endian);
	if (!z->mlx || !z->win || !z->img || !z->addr)
	{
		exit_husseyin(1, z);
	}
}

int	key_pr(int key, t_mlx *z)
{
	if(key == 65307)
	{
		exit_husseyin(0, z);
		//return(0);
	}
	return (0);
}
void	hooks(t_mlx *z)
{
	//mlx_key_hook(z->win, move, z);
	printf("HOK");
	mlx_hook(z->win, 2, 1L << 0, key_pr, z);
	//mlx_mouse_hook(z->win, zoom, p);
}

void	my_mlx_pixel_put(t_mlx *z, int i, int j, int color)
{
	char	*dst;

	dst = z->addr + (j * z->line_length + i * (z->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}
