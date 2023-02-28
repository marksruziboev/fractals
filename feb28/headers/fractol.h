/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maruzibo <maruzibo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 13:46:38 by maruzibo          #+#    #+#             */
/*   Updated: 2023/02/28 18:36:56 by maruzibo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef FRACTOL_H
# define FRACTOL_H

# include "mlx.h"
# include "libft.h"
# include "keys.h"
# include <stdio.h>
# include <math.h>

/*  Dimensions	*/
# define WIDTH 900
# define HEIGHT 900
# define MAX_ITERATIONS 60

/*  Fractal fractls	*/
# define MANDELBROT 1
# define JULIA 2
# define CARPET 3
# define FERN 4
# define BURNING_SHIP 5
# define MANDELBOX 6
# define TRICORN 7


typedef struct s_fr
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*data;
	int		fractl;
	double	max_r;
	double	max_i;
	double	min_r;
	double	min_i;
	double	hr;
	double	hi;
	double	sx;
	double	rx;
	double	fx;
	int		*col_arr;
	int		color_pattern;
	int		color;
}	t_fr;

/*  Fractal fractls   */
int		mandelbrot(double cr, double ci);
int		julia(t_fr *f, double cr, double ci);
int		burning_ship(double cr, double ci);
int		tricorn(double cr, double ci);
int		mandelbox(t_fr *f, double cr, double ci);
//int		sierp(t_fr *f, double zr, double zi);


/*  Draw Fractal	*/
void	render(t_fr *f);
int		julia_shift(int x, int y, t_fr *f);

/* Colors	*/
void	color_shift(t_fr *f);
void	fractl_color_mono(t_fr *f, int color);
void	fractl_color_multiple(t_fr *f, int colors[4], int n);
void	fractl_color_zebra(t_fr *f, int color);
void	fractl_color_triad(t_fr *f, int color);
void	fractl_color_tetra(t_fr *f, int color);
void	fractl_color_opposites(t_fr *f, int color);
void	fractl_color_contrasted(t_fr *f, int color);
void	fractl_color_graphic(t_fr *f, int color);
int		get_percent_color(int color, double percent);

/*  Events   */
int		key_event(int keycode, t_fr *mlx);
int		mouse_event(int keycode, int x, int y, t_fr *mlx);

/* Initialization */
void	clean_init(t_fr *f);
void	reinit_img(t_fr *f);
void	init(t_fr *f);
void	get_complex_layout(t_fr *f);
void	get_color(t_fr *f, int ac, char **av);
double	ft_atof(char *str);

/*  Utils   */
int		end_fractol(t_fr *mlx);
void	clean_exit(int error_code, t_fr *f);
int		msg(char *str1, char *str2, int errno);
void	help_msg(t_fr *f);
void	print_controls(void);

#endif
