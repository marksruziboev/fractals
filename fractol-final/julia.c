/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maruzibo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 16:36:29 by maruzibo          #+#    #+#             */
/*   Updated: 2023/02/15 16:36:34 by maruzibo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"


/*int	click_julia(int x, int y, t_vect *b)
{
	f->r = f->min_r + (double)x * (f->max_r - f->min_r) / WIDTH;
	f->ci = f->max_i + (double)y * (f->min_i - f->max_i) / HEIGHT;
	render(f);
	return (0);
}*/
int	julia(t_mlx *z)
{
	int		n;
	double	tmp;

	n = 0;
	while (n < OMEGA) 
	{
		if ((z->x * z->x + z->y * z->y) > 4.0)
			break ;
		tmp = 2 * z->x * z->y + z->cy;
		z->x = z->x * z->x - z->y * z->y + z->cx;
		z->y = tmp;
		n++;
	}
	return (n);
}

void	plot_julia(t_mlx *z)
{
	int	i;
	int	j;

	j = -1;
	while(++j < HEIGHT)
	{
		i = -1;
		while(++i < WIDTH)
			my_mlx_pixel_put(z, i, j, julia(z) * 0x0C0F00);
	}
}
