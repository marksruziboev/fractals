/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maruzibo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 13:25:15 by maruzibo          #+#    #+#             */
/*   Updated: 2022/10/20 14:06:28 by maruzibo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t smem, size_t size)
{
	void	*place;

	place = (char *) malloc(smem * size);
	if (! place)
		return (NULL);
	ft_bzero(place, (smem * size));
	return (place);
}
