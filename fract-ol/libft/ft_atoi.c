/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maruzibo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 16:26:28 by maruzibo          #+#    #+#             */
/*   Updated: 2022/10/16 18:46:35 by maruzibo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_isspace(char c)
{
	if (c == ' ' || c == '\n' || c == '\t'
		|| c == '\v' || c == '\f' || c == '\r')
		return (1);
	return (0);
}

int	ft_atoi(const char *s)
{
	int				k;
	int				sign;
	long long int	num;

	sign = 1;
	num = 0;
	k = 0;
	while (ft_isspace(s[k]))
		k++;
	if (s[k] == '+' || s[k] == '-')
	{
		if (s[k] == '-')
			sign = sign * (-1);
		k++;
	}
	while (s[k] >= '0' && s[k] <= '9')
	{
		num = num * 10 + s[k] - '0';
		if (sign * num > 2147483647)
			return (-1);
		else if (num * sign < -2147483648)
			return (0);
		k++;
	}
	return (sign * num);
}
