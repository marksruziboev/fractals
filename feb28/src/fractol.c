/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maruzibo <maruzibo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 13:53:40 by maruzibo          #+#    #+#             */
/*   Updated: 2023/02/28 15:47:28 by maruzibo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "fractol.h"

/* type_cmp:
*	Parses the given fractal type argument and checks against
*	the name (i.e. "mandelbrot"), the associated letter (i.e. "M")
*	and the associated number (i.e. "1").
*	Returns true if the argument matches one of these requirements,
*	false if not.
*/
static int	type_cmp(char *av, char *str, char c, char n)
{
	int	i;

	i = 0;
	while (av[i])
	{
		av[i] = ft_tolower(av[i]);
		i++;
	}
	if (!ft_strncmp(av, str, ft_strlen(str) + 1))
		return (1);
	else if (av[1] == '\0' && (av[0] == c || av[0] == n))
		return (1);
	return (0);
}

/* get_fractl:
*	Retrieves the fractl specified in program arguments.
*	If no valid fractl was provided, it displays a help
*	message and quits the program.
*/
static void	get_fractl(t_fr *f, char **av)
{
	if (type_cmp(av[1], "mandelbrot", 'm', '1'))
		f->fractl = MANDELBROT;
	else if (type_cmp(av[1], "julia", 'j', '2'))
		f->fractl = JULIA;
	else if (type_cmp(av[1], "burning ship", 'b', '3'))
		f->fractl = BURNING_SHIP;
	else if (type_cmp(av[1], "tricorn", 't', '4'))
		f->fractl = TRICORN;
	else if (type_cmp(av[1], "mandelbox", 'x', '5'))
		f->fractl = MANDELBOX;
	else
		help_msg(f);
}

/* get_julia_starting_values:
*	Checks whether starting values were provided at program launch
*	for the Julia fractl. If not, default Julia values are assigned.
*	If values were provided, parses them, returning an error message
*	if the values are not valid.
*/
static void	get_julia_starting_values(t_fr *f, int ac, char **av)
{
	if (f->fractl != JULIA || ac == 2)
	{
		f->hr = -0.766667;
		f->hi = -0.090000;
		return ;
	}
	if (ac == 3)
		help_msg(f);
	if (!ft_strchr(av[2], '.'))
		help_msg(f);
	if (!ft_strchr(av[3], '.'))
		help_msg(f);
	f->hr = ft_atof(av[2]);
	f->hi = ft_atof(av[3]);
	if (f->hr > 2.0 || f->hr < -2.0)
		help_msg(f);
	if (f->hi >= 2.0 || f->hi <= -2.0)
		help_msg(f);
}

/* handle_args:
*	Retrieves the fractl, the julia starting values and the color from
*	the arguments passed at program launch.
*/
static void	handle_args(t_fr *f, int ac, char **av)
{
	get_fractl(f, av);
	if (f->fractl != JULIA && ac > 3)
		help_msg(f);
	else if (f->fractl == JULIA && ac > 5)
		help_msg(f);
	get_julia_starting_values(f, ac, av);
	get_color(f, ac, av);
}

/* main:
*	Initializes the fractol data structure, prints the program controls,
*	opens a new window and registers hooks to detect user interactions.
*	Loops infinitely until the user quits the process.
*/
int	main(int ac, char **av)
{
	t_fr	f;

	if (ac < 2)
		help_msg(&f);
	clean_init(&f);
	handle_args(&f, ac, av);
	init(&f);
	render(&f);
	print_controls();
	mlx_hook(f.win, EVENT_CLOSE_BTN, 0, end_fractol, &f);
	mlx_key_hook(f.win, key_event, &f);
	mlx_mouse_hook(f.win, mouse_event, &f);
	mlx_loop(f.mlx);
}
