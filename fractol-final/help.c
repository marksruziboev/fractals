/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maruzibo <maruzibo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 12:31:31 by maruzibo          #+#    #+#             */
/*   Updated: 2023/05/14 16:12:24 by maruzibo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	exit_husseyin(int code, t_mlx *z)
{
	if (!z)
		exit(code);
	mlx_destroy_image(z->mlx, z->img);
	mlx_destroy_window(z->mlx, z->win);
	mlx_destroy_display(z->mlx);
	if (z->mlx)
		free(z->mlx);
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
	ft_putendl_fd("\t4 - Rational Julia", 1);
	ft_putstr_fd("\nFor Julia, you may specify starting values for the\n", 1);
	ft_putstr_fd("Values must be between\n", 1);
	ft_putendl_fd("-2.0 and 2.0 and must contain a decimal point. (1 = 1.0)",
		1);
	ft_putendl_fd("\t For example:\t", 1);
	ft_putendl_fd("./fractol 2\n\t\t./fractol 2 0.285 0.01 \e[0m", 1);
}

void	controls(void)
{
	ft_putendl_fd("\n              Control keys              ", 1);
	ft_putendl_fd("To move  left; up;  right;  down use arrow keys).", 1);
	ft_putendl_fd("+/- or scroll wheel\tzoom in and out.", 1);
	ft_putendl_fd("Spacebar\t\tchange color schemes.", 1);
	ft_putendl_fd("Left click\t\tchanges Julia sets.", 1);
	ft_putendl_fd("ESC or close window\tquit fractol.", 1);
}

void	help_msg(t_mlx *z)
{
	(void)z;
	ft_putendl_fd("|======YOUR FRACTOL STORY BEGINS HERE======|", 1);
	ft_putendl_fd(" ", 1);
	fractals();
}
