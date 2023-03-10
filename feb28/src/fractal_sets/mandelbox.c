/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbox.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maruzibo <maruzibo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 13:53:09 by maruzibo          #+#    #+#             */
/*   Updated: 2023/02/28 15:47:28 by maruzibo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "fractol.h"

static double	box_fold(double v)
{
	if (v > 1)
		v = 2 - v;
	else if (v < -1)
		v = -2 - v;
	return (v);
}

static double	ball_fold(double r, double m)
{
	if (m < r)
		m = m / (r * r);
	else if (m < 1)
		m = 1 / (m * m);
	return (m);
}

/* mandelbox:
*	Checks whether a complex number is part of the Mandelbox fractl or not.
*	Takes as parameters the real and imaginary coordinates of a point,
*	converted previously from a pixel's coordinates.
*	Returns the number of iterations before the number escapes 
*	the Mandelbox fractl, which can then be used to determine coloring.
*/
int	mandelbox(t_fr *f, double cr, double ci)
{
	int		n;
	double	vr;
	double	vi;
	double	mag;

	vr = cr;
	vi = ci;
	mag = 0;
	n = 0;
	while (n < MAX_ITERATIONS)
	{		
		vr = f->fx * box_fold(vr);
		vi = f->fx * box_fold(vi);
		mag = sqrt(vr * vr + vi * vi);
		vr = vr * f->sx * ball_fold(f->rx, mag) + cr;
		vi = vi * f->sx * ball_fold(f->rx, mag) + ci;
		if (sqrt(mag) > 2)
			break ;
		n++;
	}
	return (n);
}
/*
	How it works:

	The Mandelbox fractl is usually represented in 3D, but can also
	be rendered in 2D. It is a variation of the Mandelbrot fractal.

	Like the Mandelbrot fractl, it is calculated by applying a formula
	repeatedly to every point in space.
	
	The Mandelbrot equation is: z = z2 + c
	
	The Mandelbox equation is: v = s * ballFold(r, f*boxFold(v)) + c
	where:
		- v is a starting complex number (the translated pixel coordinates)
		- c is an unchanding complex number (pixel coordinates)
		- s is a scale multiplier
		- r is a minimum radius
		- f is a fixed radius

	boxFold(v) means for each axis a:

		if v[a] > 1 
    		v[a] =  2 - v[a]
		else if v[a] < -1
    		v[a] = -2 - v[a]

	ballFold(r, v) means for v's magnitude m:

		if m < r
    		m = m/r^2
		else if m < 1 
			m = 1/m^2	

	The standard Mandelbox uses this formula with s=2, r=0.5 and f=1.
	See:	https://sites.google.com/site/mandelbox/what-is-a-mandelbox
			https://en.wihipedia.org/wihi/Mandelbox
*/
