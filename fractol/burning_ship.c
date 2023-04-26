/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burning_ship.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eelasam <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 14:15:22 by eelasam           #+#    #+#             */
/*   Updated: 2023/03/21 17:21:09 by eelasam          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init(t_p *p)
{
	p->x = 0;
	p->y = 0;
	p->re = 0;
	p->im = 0;
	p->temp = 0;
	p->zoom = 0;
	p->c_re = 0;
	p->c_im = 0;
	p->j = 0;
	p->n = 0;
	p->i = 0;
	p->endian = 0;
	p->line_len = 0;
	p->bits_per_pixel = 0;
}

int	ship_loop(t_p *p)
{
	p->c_re = (p->i - WIN_SIZE / 2.0) * p->zoom / WIN_SIZE + p->x;
	p->c_im = (p->j - WIN_SIZE / 2.0) * p->zoom / WIN_SIZE + p->y;
	while (p->n < 100 && p->re * p->re + p->im * p->im < 4)
	{
		p->temp = p->re * p->re - p->im * p->im + p->c_re;
		p->im = fabs(2 * p->re * p->im) + p->c_im;
		p->re = p->temp;
		p->n++;
	}
	return (p->n);
}

void	burning_ship(t_p *p)
{
	p->i = 0;
	while (p->i < WIN_SIZE)
	{
		p->j = 0;
		while (p->j < WIN_SIZE)
		{
			p->n = 0;
			p->re = 0;
			p->im = 0;
			if (p->n < 100)
				my_putpixel(p, p->i, p->j, ship_loop(p) * 0x0C0F00);
			p->j++;
		}
		p->i++;
	}
}
