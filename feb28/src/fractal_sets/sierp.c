/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sierp.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maruzibo <maruzibo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 18:21:12 by maruzibo          #+#    #+#             */
/*   Updated: 2023/02/28 18:55:21 by maruzibo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	sierp(t_fr *f, double zr, double zi)
{
	double	w = 0.33333333;
	double	e = 0.66666666;

	int i;

	i = -1;
	while(++i < MAX_ITERATIONS)
	{
		zr = 3*zr - floor(3*zr); 
		zi = 3*zi - floor(3*zi);
		if (zr > w && zi > w && zr < e && zi < e)
			return(i);
	}
	return(i);
}
