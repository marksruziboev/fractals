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

/*void    pars_inpt(int argc, char **argv, t_mlx *z)
{
    if (argc == 1)
    {
        fractals();
        exit_husseyin(1, z);
    }
    else if (argc == 2)
    {
        if (!ft_strncmp(argv[1], "1", 2))
            plot_mandelbrot(f);
        else if (!ft_strncmp(argv[1], "2", 2))
            plot_julia(f);
        else if (!ft_strncmp(argv[1], "3", 2))
            plot_mandelbrot(f);
        else if (!ft_strncmp(argv[1], "4", 2))
            plot_fern(f);
    } 
    else if (argc == 4 && !ft_strncmp(argv[1], "2", 2))
    {
        if (!ft_isnum(argv[2]) && !ft_isnum(argv[3]))
            exit_husseyin(1, w);
        w->cx = ft_ator(argv[2]);
        w->cy = ft_ator(argv[3]);
        plot_julia(f);
    }
    else 
        exit_husseyin(1, w);
}*/

int main(int argc, char **argv)
{
    /*t_mlx *w;

    w = malloc(sizeof(t_mlx));
    init(w);
    help_msg(w);
    controls();
    w->cx = 0;
    w->cy = 0.01;
    img_wind(w, "Julia");
    //plot_julia(w);
    //plot_fractal(w);
    mlx_loop(w->mlx);*/
    while(--argc >= 0)
        printf("argc=%d, %d\n", argc, ft_isnum(argv[argc]));
    return (0);
}