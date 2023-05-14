/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maruzibo <maruzibo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 18:46:17 by maruzibo          #+#    #+#             */
/*   Updated: 2023/05/14 14:24:36 by maruzibo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "./libft/libft.h"
# include "./mlx_linux/mlx.h"
# include "color.h"
# include "key_code.h"
# include <X11/keysym.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

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

# define MLX_ERROR 1

typedef struct s_mlx
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*addr;
	double	x;
	double	y;
	double	x_max;
	double	y_max;
	double	x_min;
	double	y_min;
	double	cx;
	double	cy;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		f;

}			t_mlx;

void		img_wind(t_mlx *z);
void		my_mlx_pixel_put(t_mlx *z, int i, int j, int color);
void		plot_rat_julia(t_mlx *z);
void		plot_fractal(t_mlx *z);
void		init_fractal(t_mlx *z);
void		plot_mandelbrot(t_mlx *z);
void		plot_carpet(t_mlx *z);
void		plot_fern(t_mlx *z);
void		plot_julia(t_mlx *z);
void		julia_extrmals(t_mlx *z);
void		init(t_mlx *z);
void		ft_free(char **d);
void		ft_csh(t_mlx *z);
void		pars_inpt(int argc, char **argv, t_mlx *z);
void		help_msg(t_mlx *z);
void		fractals(void);
void		controls(void);
void		hooks(t_mlx *z);

int			escape_time(t_mlx *z);
int			key_pr(int keycode, t_mlx *z);
int			mouse_event(int keycode, int i, int j, t_mlx *z);
int			click_julia(t_mlx *z, int i, int j);
int			ft_color(int n);
int			exit_husseyin(int code, t_mlx *z);

double		ft_ator(char *s, t_mlx *z);

double		rnd(double x);

#endif
