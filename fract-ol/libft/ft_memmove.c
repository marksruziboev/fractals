/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maruzibo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 17:05:55 by maruzibo          #+#    #+#             */
/*   Updated: 2022/10/29 20:40:58 by maruzibo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	size_t	k;
	char	*d;
	char	*s;

	if ((!dst && !src) || n == 0)
		return (dst);
	d = (char *)dst;
	s = (char *)src;
	k = 0;
	if (dst < src)
	{
		while (k < n)
		{
			d[k] = s[k];
			k++;
		}
	}
	else
	{
		while (n-- > 0)
			d[n] = s[n];
	}
	return (dst);
}
