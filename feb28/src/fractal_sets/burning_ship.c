/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burning_ship.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maruzibo <maruzibo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 13:52:52 by maruzibo          #+#    #+#             */
/*   Updated: 2023/02/28 15:47:28 by maruzibo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "fractol.h"

/* burning_ship:
*	Checks whether a complex number is part of the Burning Ship fractl or not.
*	Takes as parameters the real and imaginary coordinates of a point,
*	converted previously from a pixel's coordinates.
*	Returns the number of iterations before the number escapes 
*	the Burning Ship fractl, which can then be used to determine coloring.
*/
int	burning_ship(double cr, double ci)
{
	int		n;
	double	zr;
	double	zi;
	double	tmp;

	zr = 0;
	zi = 0;
	n = 0;
	while (n < MAX_ITERATIONS)
	{
		if ((zr * zr + zi * zi) > 4.0)
			break ;
		zr = fabs(zr);
		zi = fabs(zi);
		tmp = 2 * zr * zi + ci;
		zr = zr * zr - zi * zi + cr;
		zi = tmp;
		n++;
	}
	return (n);
}
/*
	How it works:

	The Burning Ship fractal is a distortion of the Mandelbrot
	fractal. It uses the same equation to calculate the fractl, but
	uses absolute values of zr and zi at each iteration.
*/
