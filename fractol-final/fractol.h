/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maruzibo <maruzibo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 18:46:17 by maruzibo          #+#    #+#             */
/*   Updated: 2023/04/25 12:51:03 by maruzibo         ###   ########.fr       */
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


//size of the window
# define WIDTH 900
# define HEIGHT 900
# define OMEGA 60

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
	double		x;
	double		y;
	double		x_max;
	double		y_max;
	double		x_min;
	double		y_min;
	double		cx;
	double		cy;
	int			*color;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
		
}			t_mlx;


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

void    img_wind(t_mlx *w, char *str);
void	my_mlx_pixel_put(t_mlx *w, int i, int j, int color);

int		julia(t_mlx *z);
void    plot_fractal(t_mlx *w);
void	plot_julia(t_mlx *w);
void    init(t_mlx *w);
void	exit_husseyin(int code, t_mlx *w);


double		rnd(double x);

#endif

