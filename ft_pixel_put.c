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

int	main(void)//(int argc, char **v)
{
	//void	*mlx;
	//void	*mlx_win;
	t_data	img;
	t_vec z0,z1,z2;
	t_vect c;
	
	c.x = 0.285;
	c.y = 0.01;
	
	/*if (argc == 1)
	{
		printf("fuck you");
		return (0);
	}*/
	//0.285 + 0.01i
	
	z0.x = 0;
	z0.y = 0;
	
	/*z1.x = 1800;
	z1.y = 800;
	
	z2.x = 50;
	z2.y = 800;*/

	img.mlx = mlx_init();
	img.mlx_win = mlx_new_window(img.mlx, WIDTH, HEIGHT, "Hello world!");
	img.img = mlx_new_image(img.mlx, WIDTH, HEIGHT);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	
	//if (v[1] == "S")
	ehabx(&img,  0x00FF0000);
	//else if(v[1] == "J")
	//	jeyanx(c, &img, 0x00FF0000);
	//else if (v[1] == "M")
	//	deyanx(c, &img, 0x00FF0000);
	mlx_put_image_to_window(img.mlx, img.mlx_win, img.img, 0, 0);
	
	// Setup hooks  
	//mlx_loop_hook(img.mlx, &handle_no_event, &img);
	//mlx_key_hook(img.mlx_win, &key_input, &img);
	//mlx_hook(img.mlx_win, 17, 0, &click_destroy, &img);
	mlx_loop(img.mlx);
	// we will exit the loop if there's no window left, and execute this code 
	//mlx_destroy_window(img.mlx, img.mlx_win);
	//mlx_destroy_display(img.mlx);
	
	
	return(0);	
}

