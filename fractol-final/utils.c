/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maruzibo <maruzibo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 19:24:57 by marvin            #+#    #+#             */
/*   Updated: 2023/05/13 15:14:05 by maruzibo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*This function projects [-2, 2]^2 square to the window of pixels*/
int ft_color(int n)
{
  if (n % 4 == 0)
    return (ORANGE);
  else if (n % 4 == 1)
    return (GREEN);
  else if (n % 4 == 2)
    return (RED);
  else
    return (BLUE);
  return (0);
}
void	ft_csh(t_mlx *z)
{
	if (z->mlx && z->img)
    mlx_destroy_image(z->mlx, z->img);
  z->img = mlx_new_image(z->mlx, WIDTH, HEIGHT);
	z->addr = mlx_get_data_addr(z->img, &z->bits_per_pixel, &z->line_length,
			&z->endian);
	if (!z->img || !z->addr)
	{
		exit_husseyin(1, z);
	}
	if (z->color == BLACK)
    z->color += 256 * 32;
  else if (z->color == WHITE)
    z->color /= 2;
  else
    z->color += 256 * 32;
}
/*
This function converts string into double
*/
int ishere(char *s, char ch)
{
  while(*s)
  {
    if (*s == ch)
      return (1);
    s++;
  }
  return (0);
}
double ft_ator(char *s, t_mlx *z)
{
  char **v;
  double  r;
  int i;

  if (!ft_isnum(s))
  {
    fractals();
    exit_husseyin(1, z);
  }
  if (!ishere(s, '.')) 
  {
    ft_putendl_fd("Please insert one integer and two doubles!", 2);
    exit_husseyin(1, z);
  }
  v = ft_split(s, '.');
  r = 1.0;
  i = ft_strlen(v[1]);
  while(--i >= 0)
    r = r/10;
  if (v[0][0] != '-')
    r = (double)ft_atoi(v[0]) + (double)ft_atoi(v[1]) * r;
  else 
    r = (double)ft_atoi(v[0]) - (double)ft_atoi(v[1]) * r;
  ft_free(v);
  return (r);
}
