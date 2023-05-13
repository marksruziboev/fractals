/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maruzibo <maruzibo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 18:46:17 by maruzibo          #+#    #+#             */
/*   Updated: 2023/05/13 15:02:15 by maruzibo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "./mlx_linux/mlx.h"
# include "./libft/libft.h"
# include <X11/keysym.h>
#include <stdlib.h>
#include <unistd.h>
# include <stdio.h>
# include <math.h>
#include "key-code.h"
#include "color.h"


//size of the window
# define WIDTH 729
# define HEIGHT 729
# define OMEGA 60
# define SIERP 729

// fractals
# define MANDELBROT 1
# define JULIA 2
# define BURNING_SHIP 3
# define TRICORN 4
# define MANDELBOX 5

#define MLX_ERROR 1


typedef struct	s_mlx 
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*addr;
	char	*title;
	double		x;
	double		y;
	double		x_max;
	double		y_max;
	double		x_min;
	double		y_min;
	double		cx;
	double		cy;
	int			color;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	int			f;
		
}			t_mlx;


typedef	struct	s_vec
{
	double  x;
	double  y;
}			t_vec;

typedef	struct	s_ivec
{
	int  x;
	int  y;
}			t_ivec;
/*void	jeyanx(t_vec c, t_da *data, int color);
void	ehabx(t_data *data, int color);

int		julia_shift(int x, int y, t_fractol *f);
int		julia(t_fractol *f, t_vect z);
int		handle_no_event(void *data);
int		key_input(int keysym, t_data *data);
int		click_destroy(t_data *data);*/


/*
Help messages
*/

//void	help_msg(t_fr *f); // this also exist frees the struct

void    img_wind(t_mlx *z);
void	my_mlx_pixel_put(t_mlx *z, int i, int j, int color);

int		escape_time(t_mlx *z);

int		key_pr(int keycode, t_mlx *z);
int		mouse_event(int keycode, int i, int j, t_mlx *z);
void	plot_rat_julia(t_mlx *z);

//static void	ft_move(t_mlx *z, double dst, char dirct);
void	plot_fractal(t_mlx *z);
int		click_julia(t_mlx *z, int i, int j);
void	init_fractal(t_mlx *z);
int ft_color(int n);

void	plot_mandelbrot(t_mlx *z);
void    plot_carpet(t_mlx *z);
void	plot_fern(t_mlx *z);
void	plot_julia(t_mlx *z);
void    julia_extrmals(t_mlx *z);
void    init(t_mlx *z);
int		exit_husseyin(int code, t_mlx *z);
void	ft_free(char **d);
void	ft_csh(t_mlx *z);

void    pars_inpt(int argc, char **argv, t_mlx *z);
void	help_msg(t_mlx *z);
void	fractals(void);
void	controls(void);
void	hooks(t_mlx *z);
double	ft_ator(char *s, t_mlx *z);




double		rnd(double x);

#endif

