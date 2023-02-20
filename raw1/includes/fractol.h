/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maruzibo <maruzibo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 16:23:44 by mcombeau          #+#    #+#             */
/*   Updated: 2023/02/19 18:39:44 by maruzibo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "mlx.h"
# include "../libft/libft.h"
# include "keys.h"
# include <stdio.h>
# include <math.h>

/*  Dimensions	*/
# define WIDTH 900
# define HEIGHT 900
# define MAX_ITERATIONS 200

/*  Fractal sets	*/
# define MANDELBROT 1
# define JULIA 2
# define BURNING_SHIP 3
# define TRICORN 4
# define MANDELBOX 5
# define FERN 6

typedef struct s_fractol
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*buf;
	int		set;
	double	min_r;
	double	max_r;
	double	min_i;
	double	max_i;
	double	kr;
	double	ki;
	double	sx;
	double	rx;
	double	fx;
	int		*palette;
	int		color_pattern;
	int		color;
}	t_f;

/*  Fractal Sets   */
int		mandelbrot(double cr, double ci);
int		julia(t_f *f, double zr, double zi);
int		burning_ship(double cr, double ci);
int		tricorn(double cr, double ci);
int		mandelbox(t_f *f, double cr, double ci);
void	
/*  Draw Fractal	*/
void	render(t_f *f);
int		julia_shift(int x, int y, t_f *f);

/* Colors	*/
void	color_shift(t_f *f);
void	set_color_mono(t_f *f, int color);
void	set_color_multiple(t_f *f, int colors[4], int n);
void	set_color_zebra(t_f *f, int color);
void	set_color_triad(t_f *f, int color);
void	set_color_tetra(t_f *f, int color);
void	set_color_opposites(t_f *f, int color);
void	set_color_contrasted(t_f *f, int color);
void	set_color_graphic(t_f *f, int color);
int		get_percent_color(int color, double percent);

/*  Events   */
int		key_event(int keycode, t_f *mlx);
int		mouse_event(int keycode, int x, int y, t_f *mlx);

/* Initialization */
void	clean_init(t_f *f);
void	reinit_img(t_f *f);
void	init(t_f *f);
void	get_complex_layout(t_f *f);
void	get_color(t_f *f, int ac, char **av);
double	ft_atof(char *str);

/*  Utils   */
int		end_fractol(t_f *mlx);
void	clean_exit(int error_code, t_f *f);
int		msg(char *str1, char *str2, int errno);
void	help_msg(t_f *f);
void	print_controls(void);

#endif
