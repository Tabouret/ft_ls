/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollier <pollier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/10 23:39:26 by pollier           #+#    #+#             */
/*   Updated: 2015/05/17 15:33:20 by pollier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char				*str;
	unsigned int		index;
	unsigned int		index2;

	index = 0;
	index2 = 0;
	if (!(str = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1))))
		return (NULL);
	while (s1[index])
	{
		str[index] = s1[index];
		index++;
	}
	while (s2[index2])
	{
		str[index + index2] = s2[index2];
		index2++;
	}
	str[index + index2] = '\0';
	return (str);
}
