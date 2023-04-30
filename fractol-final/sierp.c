/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sierp.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maruzibo <maruzibo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 15:39:37 by maruzibo          #+#    #+#             */
/*   Updated: 2023/04/30 11:57:21 by maruzibo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
/* Sierpinski carpet
This function returns an integer, 
where the orbit of a point falls into removed square.

We use it to dynamically color the carpet
*/
/*int	map(int x)
{
	int	w;

	w = 729;
	if(x >= 0 && 3 * x <  w)
		return(3 * x);
	else if (3 * x >= w  && 3 * x < 2 * w)
		return(3 * x - w);
	else //(x >= 2 * w / 3 && x < w)
		return(3 * x - 2 * w);
}

int	escape_carpet(t_mlx *z)
{
	int	w;
	int	x;
	int	y;
	int i;
	
	w = 729;
	i = -1;
	x = (int)z->x;
	y = (int)z->y;
	while (++i < OMEGA)
	{
		if ((x > w / 3	&& x < 2 * w / 2) && (y > w / 3	&& y < 2 * w / 2))
			break;
		x = map(x);
		y = map(y);
	}
	return (i);
}

void    carpet_extrmals(t_mlx *z)
{
	z->x = 0;
	z->y = 0;
	z->x_max = 729;
	z->y_max = 729;
	z->x_min = 0;
	z->y_min = 0;
	z->cx = 0;
	z->cy = 0;
}
void	plot_carpet(t_mlx *z)
{
	int	i;
	int	j;

	carpet_extrmals(z);
	j = -1;
	while(++j <= HEIGHT)
	{
		i = -1;
		z->y = (double) j;
		while(++i <= WIDTH)
		{
			z->x = (double) i;
			my_mlx_pixel_put(z, i, j, 10* (escape_carpet(z) +1) * 0x0C0F00);
		}
	}
	mlx_put_image_to_window(z->mlx, z->win, z->img, 0, 0);
}
*/

int	escape_carpet(double x, double y)
{
    int i = 0;

    int cx, cy;
    int w = WIDTH / 3;
    while (i < OMEGA && w > 1)
    {
        cx = (int)(x / w) * w;
        cy = (int)(y / w) * w;
        if ((cx / w) % 3 == 1 && (cy / w) % 3 == 1)
            return i;
        x = fmod(x, w) * 3.0;
        y = fmod(y, w) * 3.0;
        w /= 3;
        i++;
    }
    return i;
}

void	plot_carpet(t_mlx *z)
{
	int	i;
	int	j;
	double x, y;

	j = -1;
	while(++j <= HEIGHT)
	{
		i = -1;
		y = (double)j;
		while(++i <= WIDTH)
		{
			x = (double)i;
			int color = 10 * (escape_carpet(x, y) + 1) * 0x0C0F00;
			my_mlx_pixel_put(z, i, j, color);
		}
	}
	mlx_put_image_to_window(z->mlx, z->win, z->img, 0, 0);
}
