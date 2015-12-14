/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollier <pollier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/11 02:26:55 by pollier           #+#    #+#             */
/*   Updated: 2015/11/07 06:01:28 by pollier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int		ft_ilen(int i)
{
	int index;
	int	stop;

	index = 0;
	stop = 1;
	while (stop)
	{
		stop = i / 10;
		i /= 10;
		index++;
	}
	return (index - 1);
}

char			*ft_itoa(int n)
{
	char			*str;
	int				index;
	unsigned int	nplus;

	index = ft_ilen(n) + ((n < 0) ? 2 : 1);
	if (!(str = malloc(sizeof(char) * (index + 1))))
		return (NULL);
	if (n < 0)
		str[0] = '-';
	str[index] = '\0';
	if (n < 0)
		nplus = -n;
	else
		nplus = n;
	while (index && (n < 0) ? (index - 1) : (index))
	{
		str[index - 1] = (char)('0' + (nplus % 10));
		nplus /= 10;
		index--;
	}
	return (str);
}
