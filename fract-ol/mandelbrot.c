/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maruzibo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 15:44:22 by maruzibo          #+#    #+#             */
/*   Updated: 2023/02/15 15:45:04 by maruzibo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/* mandelbrot:
*   This functions checks whether a complex number is in the Mandelbrot set or not.
*   for z \in C we look at |z|.
*   Returns the number of iterations before the number escapes 
*   the Mandelbrot set, which can then be used to determine coloring.
*/
int	mandelbrot(t_vect c) // arguments were double cr, double ci
{
	int		n;
	t_vect	z;
	double	tmp;

	z.x = 0;
	z.y = 0;
	n = 0;
	while (n < OMEGA) // Omega = MAX_ITERATIONS
	{
		if ((z.x * z.x + z.y * z.y) > 6.0)
			break ;
		tmp = 2 * z.x * z.y + c.x;
		zr = z.x * z.x - z.y * z.y + c.x;
		z.y = tmp;
		n++;
	}
	return (n);
}
