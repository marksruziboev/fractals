/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maruzibo <maruzibo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 18:32:39 by maruzibo          #+#    #+#             */
/*   Updated: 2023/04/28 10:59:22 by maruzibo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	else if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}

int	ft_isnum(char *s)
{
	int	c;
	int	i;
	
	c = 0;
	i = 0;
	while ((s[i] >= '0' && s[i] <= '9') || s[i] == '-' || s[i] == '.')
	{
		if (s[i] == '-' && i > 0)
			break ;
		if (s[i] == '.') 
			c++;
		if (c > 1)
			break ;
		i++;
	}
	if (s[i] == '\0')
		return (1);
	else
		return (0);
}
