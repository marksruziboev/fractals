/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maruzibo <maruzibo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 12:31:31 by maruzibo          #+#    #+#             */
/*   Updated: 2023/04/25 12:39:44 by maruzibo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	exit_husseyin(int code, t_fr *f)
{
	if (!f)
		exit(code);
	if (f->col_arr)
		free(f->col_arr);
	if (f->img)
		mlx_destroy_image(f->mlx, f->img);
	if (f->win && f->mlx)
		mlx_destroy_window(f->mlx, f->win);
	if (f->mlx)
	{
		mlx_loop_end(f->mlx);
		mlx_destroy_display(f->mlx);
		free(f->mlx);
	}
	exit(exit_code);
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
	ft_putendl_fd("\e[36mUsage example:\t", 1);
	ft_putendl_fd("./fractol J\n\t\t./fractol J 0.285 0.01 \e[0m", 1);
}

void	controls(void)
{
	ft_putendl_fd("\n              Control keys              ", 1);
	ft_putendl_fd("To move  left A; up W;  right D;  down S (or arrow keys).", 1);
	ft_putendl_fd("+/- or scroll wheel\tzoom in and out.", 1);
	ft_putendl_fd("Spacebar\t\tchange color schemes.", 1);
	ft_putendl_fd("Left click\t\tshift Julia fractl [Julia only].", 1);
	ft_putendl_fd("1, 2, 3, 4, 5\t\tswitch fractals.", 1);
	ft_putendl_fd("ESC or close window\tquit fract'ol.", 1);
}
void	help_msg(t_fr *f)
{
	ft_putendl_fd("|		FRACT'OL		|", 1);
	fractals();
	//print_color_options();
	exit_husseyin(EXIT_FAILURE, f);
}