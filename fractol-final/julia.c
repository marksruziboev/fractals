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
int	julia(t_vec *z, t_vec *c)
{
	int		n;
	double	tmp;

	n = 0;
	while (n < OMEGA) 
	{
		if ((z->x * z->x + z->y * z->y) > 4.0)
			break ;
		tmp = 2 * z->x * z->y + c->y;
		z->x = z->x * z->x - z->y * z->y + c->x;
		z->y = tmp;
		n++;
	}
	return (n);
}

void	plot_julia(t_mlx *w, t_vec *c)
{
	t_ivec p;
	t_vec	z;
	
	t_vec  project(int q1, int q2)
	p.y = -1;
	while(++p.y < HEIGHT)//julia(z, c))
	{
		p.x = -1;
		while(++p.x < HEIGHT)
		{
			z.x = project(p.x, p.y).x;
			z.y = project(p.x, p.y).y;
			my_mlx_pixel_put(w, &p, julia(&z, c)* 0x0C0F00);
		}
	}
}
