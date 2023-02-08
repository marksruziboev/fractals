/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maruzibo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 18:46:17 by maruzibo          #+#    #+#             */
/*   Updated: 2023/02/06 18:53:50 by maruzibo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "mlx_linux/mlx.h"
//# include "libft.h"
//# include "keys.h"
# include <stdio.h>
# include <math.h>

//constants used in the program
# define WIDTH 1200
# define HEIGHT 800


typedef struct	s_data 
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	
}			t_data;

typedef struct s_vec
{
	int	x;
	int	y;
}		t_vec;

typedef struct s_vect
{
	double x;
	double y;
} t_vect;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
void	my_line(t_data *data, t_vec z0, t_vec z1, int color);
void	triangle(t_data *data, t_vec z0, t_vec z1, t_vec z2, int color);
void	deyanx(t_vect c, t_data *data, int color);
void	jeyanx(t_vect c, t_data *data, int color);
void	ehabx(t_data *data, int color);

#endif

