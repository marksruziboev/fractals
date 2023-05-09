/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maruzibo <maruzibo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 14:04:32 by maruzibo          #+#    #+#             */
/*   Updated: 2023/05/09 17:57:11 by maruzibo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void    pars_inpt(int argc, char **argv, t_mlx *z)
{
   if (argc == 2)
    {
        if (!ft_strncmp(argv[1], "1", 2) || !ft_strncmp(argv[1], "M", 2))
            z-> f = 1;
        else if (!ft_strncmp(argv[1], "2", 2) || !ft_strncmp(argv[1], "J", 2))
            z-> f = 2;
        else if (!ft_strncmp(argv[1], "3", 2) || !ft_strncmp(argv[1], "S", 2))
            z-> f = 3;
        else if (!ft_strncmp(argv[1], "4", 2) || !ft_strncmp(argv[1], "B", 2))
            z-> f = 4;
    } 
    else if (argc == 4 && (!ft_strncmp(argv[1], "2", 2) || !ft_strncmp(argv[1], "J", 2)))
    {
        if (!ft_isnum(argv[2]) && !ft_isnum(argv[3]))
            exit_husseyin(1, z);
        z->cx = ft_ator(argv[2]);
        z->cy = ft_ator(argv[3]);
        z -> f = 2;
    }
    else 
        exit_husseyin(1, z);
}

int main(int argc, char **argv)
{
    t_mlx *z;
    
    if (argc == 1)
    {
        fractals();
        return(1);
    }
    z = malloc(sizeof(t_mlx));
    init(z);
   // controls();
    img_wind(z);
    pars_inpt(argc, argv, z);
    init_fractal(z);
    hooks(z);
    plot_fractal(z);
    mlx_loop(z->mlx);
    exit_husseyin(0, z);
    return (0);
}