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

# include "../mlx_linux/mlx.h"
# include "../libft.h"
# include <X11/keysym.h>
#include <stdlib.h>
#include <unistd.h>
# include <stdio.h>
# include <math.h>


//size of the window
# define WIDTH 1200
# define HEIGHT 800
# define OMEGA 60

// fractals
# define MANDELBROT 1
# define JULIA 2
# define BURNING_SHIP 3
# define TRICORN 4
# define MANDELBOX 5

#define MLX_ERROR 1


typedef struct	s_data 
{
	void	*img;
	void	*mlx;
	void	*mlx_win;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
		
}			t_data;

typedef struct s_ivec
{
	int	x;
	int	y;
}		t_ivec;

typedef struct s_vec
{
	double x;
	double y;
} t_vec;

typedef struct s_fr
{
	t_data	d;
	
}		t_fr;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
void	jeyanx(t_vect c, t_data *data, int color);
void	ehabx(t_data *data, int color);


void	exit_husseyin(int code, t_fr *f);

int		julia_shift(int x, int y, t_fractol *f);
int		julia(t_fractol *f, t_vect z);
int		handle_no_event(void *data);
int		key_input(int keysym, t_data *data);
int		click_destroy(t_data *data);


/*
Help messages
*/
void	fractals(void);
void	controls(void);
void	help_msg(t_fr *f); // this also exist frees the struct


double		rnd(double x);

#endif

