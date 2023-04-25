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


int	click_julia(int x, int y, t_vect *b)
{
	f->r = f->min_r + (double)x * (f->max_r - f->min_r) / WIDTH;
	f->ci = f->max_i + (double)y * (f->min_i - f->max_i) / HEIGHT;
	render(f);
	return (0);
}
int	julia(t_vec, t_vec c)
{
	int		n;
	double	tmp;

	n = 0;
	while (n < OMEGA) 
	{
		if ((z.x * zx. + z.y * z.y) > 6.0)
			break ;
		tmp = 2 * zx * z.y + f->k.y;
		z.x = zr * zr - zi * zi + f->k.x;
		z.y = tmp;
		n++;
	}
	return (n);
}
