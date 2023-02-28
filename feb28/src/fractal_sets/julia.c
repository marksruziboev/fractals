/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maruzibo <maruzibo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 13:53:03 by maruzibo          #+#    #+#             */
/*   Updated: 2023/02/28 15:47:28 by maruzibo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "fractol.h"

/* julia_shift:
*	Changes the Julia calculation hr and hi values to get a different Julia
*	fractal shape. This function should be called when the user clicks on
*	a point on the sceen.
*/
int	julia_shift(int x, int y, t_fr *f)
{
	f->hr = f->min_r + (double)x * (f->max_r - f->min_r) / WIDTH;
	f->hi = f->max_i + (double)y * (f->min_i - f->max_i) / HEIGHT;
	render(f);
	return (0);
}

/* julia:
*	Checks whether a complex number is part of the Julia fractl or not.
*	Takes as parameters the real and imaginary coordinates of a point,
*	converted previously from a pixel's coordinates.
*	Returns the number of iterations before the number escapes 
*	the Julia fractl, which can then be used to determine coloring.
*/
int	julia(t_fr *f, double zr, double zi)
{
	int		n;
	double	tmp;

	n = 0;
	while (n < MAX_ITERATIONS)
	{
		if ((zi * zi + zr * zr) > 4.0)
			break ;
		tmp = 2 * zr * zi + f->hi;
		zr = zr * zr - zi * zi + f->hr;
		zi = tmp;
		n++;
	}
	return (n);
}
/*
	How it works:

	The Julia fractl is closely related to the Mandelbrot fractl:
	its formula is identical. What differs are the complex
	number we plug into it.
	
	Mandelbrot uses 0 as a starting value for zr and zi, and
	adds pixel coordinates (cr and ci) every time it iterates.

	On the other hand, Julia starts with pixel coordinates as
	zr and zi and adds another complex number (hr and hi) every time
	it iterates.

	hr and hi values determine the shape Julia will take on.
	If hr + hi is part of the Mandelbrot fractl, Julia will be a continuous
	solid shape. If hr + hi is not part of the Mandelbrot fractl, the
	Julia fractal will be a disconnected fractl of separate islands.
	If hr + hi is a point that is close to the Mandelbrot fractal boundary,
	the same patterns we see at that point in the Mandelbrot fractal
	will emerge in the Julia fractal.
*/