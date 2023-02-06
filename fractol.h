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
# define WIDTH 900
# define HEIGHT 600


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
	double x;
	double y;
}		t_vec;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color);

#endif

