/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maruzibo <maruzibo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 19:24:57 by marvin            #+#    #+#             */
/*   Updated: 2023/05/08 16:57:45 by maruzibo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*This function projects [-2, 2]^2 square to the window of pixels*/
t_vec  step(t_mlx *w)
{
  t_vec h;
  
  h.x = (w->x_max -w->x_min)/ (double) WIDTH;
  h.y = (w->y_max -w->y_min)/ (double) HEIGHT;
  return (h);
}
/*
This function converts string into double
*/
double ft_ator(char *s)
{
  char **v;
  double  r;
  int i;

  if (!ft_isnum(s))
  {
    fractals();
    exit(1);
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
