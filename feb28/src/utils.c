/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maruzibo <maruzibo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 13:54:07 by maruzibo          #+#    #+#             */
/*   Updated: 2023/02/28 18:08:33 by maruzibo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "fractol.h"

/* clean_exit:
*	Destroys the window, the MLX image and the MLX instance,
*	and frees the color col_arr, before ending the MLX loop
*	and destroying the display. Exits the process with the provided
*	exit code.
*/
void	clean_exit(int exit_code, t_fr *f)
{
	if (!f)
		exit(exit_code);
	if (f->col_arr)
		free(f->col_arr);
	if (f->img)
		mlx_destroy_image(f->mlx, f->img);
	if (f->win && f->mlx)
		mlx_destroy_window(f->mlx, f->win);
	if (f->mlx)
	{
		mlx_loop_end(f->mlx);
		mlx_destroy_display(f->mlx);
		free(f->mlx);
	}
	exit(exit_code);
}

/* msg:
*	Displays an error message to the standard error.
*	Returns the provided error number.
*/
int	msg(char *str1, char *str2, int errno)
{
	ft_putstr_fd("Fractol: ", 2);
	ft_putstr_fd(str1, 2);
	ft_putendl_fd(str2, 2);
	return (errno);
}

/* end_fractol:
*	Exits cleanly from the program.
*	This function is registered to an MLX hook: whenever the
*	user hits the right button, this function will be called
*	automatically.
*/
int	end_fractol(t_fr *mlx)
{
	clean_exit(0, mlx);
	return (0);
}
