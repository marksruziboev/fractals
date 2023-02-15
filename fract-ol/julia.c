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

/* julia_shift:
*	Changes the Julia calculation kr and ki values to get a different Julia
*	fractal shape. This function should be called when the user clicks on
*	a point on the sceen.
*/
int	julia_shift(int x, int y, t_fractol *f)
{
	f->kr = f->min_r + (double)x * (f->max_r - f->min_r) / WIDTH;
	f->ki = f->max_i + (double)y * (f->min_i - f->max_i) / HEIGHT;
	render(f);
	return (0);
}

/* julia:
*	Checks whether a complex number is part of the Julia set or not.
*	Takes as parameters the real and imaginary coordinates of a point,
*	converted previously from a pixel's coordinates.
*	Returns the number of iterations before the number escapes 
*	the Julia set, which can then be used to determine coloring.
*/
int	julia(t_fractol *f, t_vect z)
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
