/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_exit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eelasam <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 14:21:07 by eelasam           #+#    #+#             */
/*   Updated: 2023/03/21 18:10:34 by eelasam          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	available_fractals(char **av)
{
	if (!ft_strcmp(av[1], "julia") || !ft_strcmp(av[1], "first_julia")
		|| !ft_strcmp(av[1], "second_julia") || !ft_strcmp(av[1], "mandelbrot")
		|| !ft_strcmp(av[1], "burning_ship"))
		return (0);
	return (1);
}

void	error_phrase(void)
{
	write(1, "./fractol <NAME>\n", 17);
	write(1, "Fractals Names:\n", 16);
	write(1, "* mandelbrot\n", 13);
	write(1, "* julia:\n", 9);
	write(1, "\t ** julia\n", 11);
	write(1, "\t ** first_julia\n", 17);
	write(1, "\t ** second_julia\n", 18);
	write(1, "* burning_ship\n", 15);
	exit(EXIT_FAILURE);
}

int	exit_close(t_p *p)
{
	free(p->fractal);
	mlx_destroy_image(p->ptr, p->img);
	mlx_destroy_window(p->ptr, p->win);
	mlx_destroy_display(p->ptr);
	free(p->ptr);
	free(p);
	exit(EXIT_SUCCESS);
	return (0);
}

void	ft_esc(int keycode, t_p *p)
{
	if (keycode == ESC_KEY)
	{
		free(p->fractal);
		mlx_destroy_image(p->ptr, p->img);
		mlx_destroy_window(p->ptr, p->win);
		mlx_destroy_display(p->ptr);
		free(p->ptr);
		free(p);
		exit(EXIT_SUCCESS);
	}
}
