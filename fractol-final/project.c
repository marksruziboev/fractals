/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   project.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 19:24:57 by marvin            #+#    #+#             */
/*   Updated: 2023/04/26 19:24:57 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*This function projects [-2, 2]^2 square to the window of pixels*/
t_vec  step(t_mlx *w)
{
  t_vec h;
  
  h.x = (w->x_max -w->x_min)/WIDTH;
  h.y = (w->y_max -w->y_min)/HEIGHT;
  
  return (h);
}
