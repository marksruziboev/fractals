/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pixel_put.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maruzibo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 19:00:15 by maruzibo          #+#    #+#             */
/*   Updated: 2023/01/25 19:00:21 by maruzibo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fractol.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	t_data	img;
	t_vec z0,z1,z2;
	t_vect c;
	
	c.x = 0.285;
	c.y = 0.01;
	
	//0.285 + 0.01i
	
	z0.x = 0;
	z0.y = 0;
	
	/*z1.x = 1800;
	z1.y = 800;
	
	z2.x = 50;
	z2.y = 800;*/

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, WIDTH, HEIGHT, "Hello world!");
	img.img = mlx_new_image(mlx, WIDTH, HEIGHT);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
								&img.endian);
	ehabx(&img,  0x00FF0000);
	//jeyanx(c, &img, 0x00FF0000);
	//deyanx(c, &img, 0x00FF0000);
	//triangle(&img,  z0,  z1,  z2, 0x00FF0000);
	//my_line(&img, z0, z1, 0x00FF0000);
	//my_mlx_pixel_put(&img,  500, 500, 0x00FF0000);
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
}

