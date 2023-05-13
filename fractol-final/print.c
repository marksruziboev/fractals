/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maruzibo <maruzibo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 13:54:01 by maruzibo          #+#    #+#             */
/*   Updated: 2023/05/13 14:57:50 by maruzibo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "fractol.h"

void	plot_fractal(t_mlx *z)
{
	mlx_clear_window(z->mlx, z->win);
	if (z-> f == 1)
    	plot_mandelbrot(z);
    else if (z-> f == 2)
    	plot_julia(z);
    else if (z-> f == 3)
    	plot_carpet(z);
    else if (z-> f == 4)
		plot_rat_julia(z);
	mlx_put_image_to_window(z->mlx, z->win, z->img, 0, 0);
}
