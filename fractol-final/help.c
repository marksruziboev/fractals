/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maruzibo <maruzibo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 12:31:31 by maruzibo          #+#    #+#             */
/*   Updated: 2023/05/10 15:39:11 by maruzibo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	exit_husseyin(int code, t_mlx *z)
{
	if (!z)
		exit(code);
	/*if (z->color)
	{   printf("color is not zero");
		free(z->color);
	}*/
	/*if (z->addr)
	{
		printf("addr is not zero");
		free(z->addr);
	}*/
	mlx_destroy_image(z->mlx, z->img);
	/*if (z->img)
	{
		 printf("img is not zero");
		free(z->img);
	}
	if (z->win && z->mlx)
	{
		printf("wim or mlx is not zero");
		free(z->win);
	}*/
	mlx_destroy_window(z->mlx, z->win);
	mlx_destroy_display(z->mlx);
	if (z->mlx)
	{
		//printf("mlx is not zero");
		//mlx_loop_end(z->mlx);
		free(z->mlx);
	}
	if (z)
		free(z);
	exit(code);
	return (0);
}
void	ft_free(char **d)
{
	size_t	i;

	i = 0;
	while (d[i])
	{
		free(d[i]);
		i++;
	}
	free(d);
}



void	fractals(void)
{
	
	ft_putendl_fd(" To view the fractals use the following:", 1);
	ft_putendl_fd("\t1 - Mandelbrot", 1);
	ft_putendl_fd("\t2 - Julia", 1);
	ft_putendl_fd("\t3 - Sierpinski carpet", 1);
	ft_putendl_fd("\t4 - Barnsly fern", 1);
	ft_putstr_fd("\nFor Julia, you may specify starting values for the\n", 1);
	ft_putstr_fd("initial fractal shape. Values must be between\n", 1);
	ft_putendl_fd("-2.0 and 2.0 and must contain a decimal point.", 1);
	ft_putendl_fd("\t For example:\t", 1);
	ft_putendl_fd("./fractol 2\n\t\t./fractol 2 0.285 0.01 \e[0m", 1);
}

void	controls(void)
{
	ft_putendl_fd("\n              Control keys              ", 1);
	ft_putendl_fd("To move  left A; up W;  right D;  down S (or arrow keys).",
			1);
	ft_putendl_fd("+/- or scroll wheel\tzoom in and out.", 1);
	ft_putendl_fd("Spacebar\t\tchange color schemes.", 1);
	ft_putendl_fd("Left click\t\tshift Julia fractl [Julia only].", 1);
	ft_putendl_fd("1, 2, 3, 4, 5\t\tswitch fractals.", 1);
	ft_putendl_fd("ESC or close window\tquit fract'ol.", 1);
}
void	help_msg(t_mlx *z)
{
	(void)z;
	ft_putendl_fd("|======YOUR FRACTOL STORY BEGINS HERE======|", 1);
	ft_putendl_fd(" ", 1);
	fractals();
	printf("fuck zou\n");
	printf("fuck zou\n");
	//print_color_options();
	
	//exit_husseyin(1, z);
}