/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maruzibo <maruzibo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 14:17:48 by eelasam           #+#    #+#             */
/*   Updated: 2023/04/29 16:33:07 by maruzibo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	hooks(t_p *p)
{
	mlx_key_hook(p->win, move, p);
	mlx_hook(p->win, 17, 0, exit_close, p);
	mlx_mouse_hook(p->win, zoom, p);
}

void	create_window(t_p *p)
{
	p->ptr = mlx_init();
	p->win = mlx_new_window(p->ptr, WIN_SIZE, WIN_SIZE, "fract-ol");
}

void	create_image(t_p *p)
{
	p->img = mlx_new_image(p->ptr, WIN_SIZE, WIN_SIZE);
	p->data = mlx_get_data_addr(p->img, &p->bits_per_pixel, &p->line_len,
			&p->endian);
}

void	choose_fractale(char *av, t_p *p)
{
	if (!ft_strcmp(av, "julia") || !ft_strcmp(av, "first_julia")
		|| !ft_strcmp(av, "second_julia"))
	{
		julia(av, p);
		p->fractal = ft_strdup(av);
	}
	else if (!ft_strcmp(av, "mandelbrot"))
	{
		mandelbrot(p);
		p->fractal = ft_strdup("mandelbrot");
	}
	else if (!ft_strcmp(av, "burning_ship"))
	{
		burning_ship(p);
		p->fractal = ft_strdup("burning_ship");
	}
	mlx_put_image_to_window(p->ptr, p->win, p->img, 0, 0);
}

int	main(int ac, char **av)
{
	t_p	*p;

	if (ac != 2 || available_fractals(av))
		error_phrase();
	p = malloc(sizeof(t_p));
	init(p);
	p->zoom = 4.0;
	create_window(p);
	create_image(p);
	choose_fractale(av[1], p);
	hooks(p);
	mlx_loop(p->ptr);
	return (0);
}
