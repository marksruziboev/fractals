/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maruzibo <maruzibo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 14:04:32 by maruzibo          #+#    #+#             */
/*   Updated: 2023/04/30 11:30:43 by maruzibo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*void    pars_inpt(int argc, char **argv, t_mlx *z)
{
    if (argc == 1)
        help_msg(z);
    else if (argc == 2)
    {
        if (!ft_strncmp(argv[1], "1", 2))
            plot_mandelbrot(z);
        else if (!ft_strncmp(argv[1], "2", 2))
            plot_julia(z);
        else if (!ft_strncmp(argv[1], "3", 2))
            plot_carpet(z);
        else if (!ft_strncmp(argv[1], "4", 2))
            plot_fern(z);
    } 
    else if (argc == 4 && !ft_strncmp(argv[1], "2", 2))
    {
        if (!ft_isnum(argv[2]) && !ft_isnum(argv[3]))
            exit_husseyin(1, z);
        z->cx = ft_ator(argv[2]);
        z->cy = ft_ator(argv[3]);
        plot_julia(z);
    }
    else 
        exit_husseyin(1, z);
}*/

int main() //(int argc, char **argv)
{
    t_mlx *z;
    

    z = malloc(sizeof(t_mlx));
    init(z);
    //julia_extrmals(z);
   // pars_inpt(argc, argv, z);
    //controls();
    img_wind(z, "Julia");
   // plot_julia(z);
   // plot_mandelbrot(z);
  // plot_fern(z);
  plot_carpet(z);
  
    hooks(z);
    mlx_loop(z->mlx);
   // exit_husseyin(0, z);
    return (0);
}