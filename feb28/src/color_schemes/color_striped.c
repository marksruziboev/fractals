/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_striped.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maruzibo <maruzibo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 13:50:54 by maruzibo          #+#    #+#             */
/*   Updated: 2023/02/28 18:10:06 by maruzibo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "fractol.h"

/* fill_color:
*	fractls a color for particular stripes intervals.
*	If stripes = 2, the coloring will ship a col_arr iteration,
*	if stripes = 3, the coloring will ship 2 col_arr iterations, and so on.
*/
static void	fill_color_stripe(t_fr *f, int color, int stripe)
{
	int	i;

	i = 0;
	while (i < MAX_ITERATIONS)
	{
		f->col_arr[i] = color;
		i += stripe;
	}
}

/* get_percent_color:
*	Calculates a color that is a certain percentage away
*	from the provided color. Each color channel must be calculated
*	separately. Intended to find somewhat complimentary colors.
*	(For true complimentary colors picked from the color wheel,
*	this function would need to be radically modified to use
*	HSL colors rather than RGB...)
*	Note: rgb[3] : rgb[0] = red, rgb[1] = green, rgb[2] = blue
*/
int	get_percent_color(int color, double percent)
{
	int		rgb[3];
	int		trgb[3];
	double	percentage;

	rgb[0] = (color >> 16) & 0xFF;
	rgb[1] = (color >> 8) & 0xFF;
	rgb[2] = (color >> 0) & 0xFF;
	percentage = (percent / 100) * 256;
	trgb[0] = (rgb[0] + percentage) - 256;
	trgb[1] = (rgb[1] + percentage) - 256;
	trgb[2] = (rgb[2] + percentage) - 256;
	return (0xFF << 24 | trgb[0] << 16 | trgb[1] << 8 | trgb[2]);
}

/* fractl_color_zebra:
*	fractls a zebra-striped color scheme. Colors alternate between
*	the given color and a complimentary color 50% away from the
*	first.
*/
void	fractl_color_zebra(t_fr *f, int color)
{
	int	color2;

	color2 = get_percent_color(color, 50);
	fill_color_stripe(f, color, 1);
	fill_color_stripe(f, color2, 2);
	f->col_arr[MAX_ITERATIONS - 1] = 0;
}

/* fractl_color_triad:
*	fractls a striped color scheme. Colors alternate between
*	three colors: the given color, a color 33% away from the first
*	and a color 66% away from the first.
*/
void	fractl_color_triad(t_fr *f, int color)
{
	int		triad[2];

	triad[0] = get_percent_color(color, 33);
	triad[1] = get_percent_color(color, 66);
	fill_color_stripe(f, color, 1);
	fill_color_stripe(f, triad[0], 2);
	fill_color_stripe(f, triad[1], 3);
	f->col_arr[MAX_ITERATIONS - 1] = 0;
}

/* fractl_color_tetra:
*	fractls a striped color scheme. Colors alternate between
*	four colors: the given color, a color 25% away from it,
*	a color 50% away from the first, and a color 75% away from
*	the first.
*/
void	fractl_color_tetra(t_fr *f, int color)
{
	int	tetra[3];

	tetra[0] = get_percent_color(color, 25);
	tetra[1] = get_percent_color(color, 50);
	tetra[2] = get_percent_color(color, 75);
	fill_color_stripe(f, color, 1);
	fill_color_stripe(f, tetra[0], 2);
	fill_color_stripe(f, tetra[1], 3);
	fill_color_stripe(f, tetra[2], 4);
	f->col_arr[MAX_ITERATIONS - 1] = 0;
}
