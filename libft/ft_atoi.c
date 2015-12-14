/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollier <pollier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 17:44:13 by pollier           #+#    #+#             */
/*   Updated: 2015/04/28 16:26:43 by pollier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	skip(const char *str)
{
	int	i;

	i = 0;
	while (str[i] == ' ' || str[i] == '\n' || str[i] == '\t' || str[i] == '\v'
	|| str[i] == '\f' || str[i] == '\r')
		i++;
	return (i);
}

int			ft_atoi(const char *str)
{
	unsigned int	i;
	int				neg;
	int				value;

	i = skip(str);
	value = 0;
	neg = 1;
	if (str[i] == '-')
	{
		i++;
		neg = -1;
	}
	else if (str[i] == '+')
	{
		i++;
		neg = 1;
	}
	while (str[i] && (str[i] <= 57 && str[i] >= 48))
	{
		value *= 10;
		value += (str[i] - 48);
		i++;
	}
	return (value * neg);
}
