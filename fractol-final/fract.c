/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maruzibo <maruzibo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 14:04:32 by maruzibo          #+#    #+#             */
/*   Updated: 2023/04/25 14:07:35 by maruzibo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void    pars_inpt(int argc, char **argv)
{
    if (argc == 1)
    {
        fractals();
        exit(1);
    }
    else if (argc == 2)
    {
        if (ft_atoi(argv[1]) == 1)
            plot_mandelbrot(f);
        else if (ft_atoi(argv[1]) == 2)
            plot_julia(f);
        else if (ft_atoi(argv[1]) == 3)
            plot_mandelbrot(f);
        else if (ft_atoi(argv[1]) == 4)
            plot_fern(f);
    } 
    else if (argc == 4)
    {
        
        plot_mandelbrot(f, c);
        
    }
}
