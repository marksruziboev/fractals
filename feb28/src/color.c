/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maruzibo <maruzibo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 13:53:28 by maruzibo          #+#    #+#             */
/*   Updated: 2023/02/28 18:36:09 by maruzibo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "fractol.h"

/* color_shift_special:
*	Extension of the color_shift function. Changes the color pattern.
*	The fractal can then be rendered again with different color
*	effects.
*/
static void	color_shift_special(t_fr *f)
{
	int	int_c;

	if (f->color == 0xFFFFFF)
		int_c = 0xCCCCCC;
	else
		int_c = f->color;
	if (f->color_pattern == 5)
		fractl_color_contrasted(f, int_c);
	else if (f->color_pattern == 6)
		fractl_color_opposites(f, f->color);
	else if (f->color_pattern == 7)
		fractl_color_graphic(f, f->color);
	else if (f->color_pattern == 8)
		fractl_color_multiple(f, (int [8]){0xFF0000, 0xFF7F00, 0xFFFF00,
			0x00FF00, 0x0000FF, 0x4B0082, 0x9400D3, 0xFFFFFF}, 8);
}

/* color_shift_striped:
*	Extension of the color_shift function. Changes the color pattern.
*	The fractal can then be rendered again with different color
*	effects.
*/
static void	color_shift_striped(t_fr *f)
{
	if (f->color_pattern == 2)
		fractl_color_zebra(f, f->color);
	else if (f->color_pattern == 3)
		fractl_color_triad(f, f->color);
	else if (f->color_pattern == 4)
		fractl_color_tetra(f, f->color);
	else
		color_shift_special(f);
}

/* color_shift:
*	Reinitializes the MLX image and changes the color pattern.
*	The fractal can then be rendered again with different color
*	effects.
*/
void	color_shift(t_fr *f)
{
	int	clr;

	f->color_pattern = (f->color_pattern + 1) % 9;
	reinit_img(f);
	if (f->color == 0x000000)
		clr = 0x333333;
	else
		clr = f->color;
	if (f->color_pattern == 0)
		fractl_color_mono(f, clr);
	else if (f->color_pattern == 1)
		fractl_color_multiple(f, (int [4]){0x000000, clr,
			get_percent_color(f->color, 50), 0xFFFFFF}, 4);
	else
		color_shift_striped(f);
}
