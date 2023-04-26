/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eelasam <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 14:17:18 by eelasam           #+#    #+#             */
/*   Updated: 2023/03/21 18:25:26 by eelasam          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "./mlx_linux/mlx.h"
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define WIN_SIZE 700
# define LEFT_KEY 65363
# define RIGHT_KEY 65361
# define DOWN_KEY 65362
# define UP_KEY 65364
# define ESC_KEY 65307
# define MOUSE_UP 4
# define MOUSE_DOWN 5

typedef struct s_p
{
	void	*ptr;
	void	*win;
	void	*img;
	float	x;
	float	y;
	float	re;
	float	im;
	float	temp;
	float	zoom;
	float	c_re;
	float	c_im;
	char	*data;
	char	*fractal;
	int		j;
	int		n;
	int		i;
	int		endian;
	int		line_len;
	int		bits_per_pixel;
}			t_p;

void		hooks(t_p *p);
void		mandelbrot(t_p *p);
void		error_phrase(void);
void		burning_ship(t_p *p);
void		create_image(t_p *p);
void		create_window(t_p *p);
void		julia(char *av, t_p *p);
void		choose_fractale(char *av, t_p *p);
void		my_putpixel(t_p *p, int x, int y, int color);
void		init(t_p *p);
void		ft_esc(int keycode, t_p *p);

char		*ft_strdup(const char *src);

int			ship_loop(t_p *p);
int			exit_close(t_p *p);
int			mandelbrot_loop(t_p *p);
int			ft_strcmp(char *s1, char *s2);
int			available_fractals(char **av);
int			julia_loop(char *av, t_p *p);
int			move(int keycode, t_p *p);
int			zoom(int keycode, int x, int y, t_p *p);

size_t		ft_strlen(const char *str);

#endif
