/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollier <pollier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 13:59:19 by pollier           #+#    #+#             */
/*   Updated: 2015/11/11 02:28:30 by pollier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(const char *s1, size_t i)
{
	unsigned int	j;
	char			*s2;

	if (!s1)
		return (NULL);
	s2 = ft_strnew(sizeof(char) * (ft_strnlen(s1, i) + 1));
	if (!s2)
		return (NULL);
	j = 0;
	while (s1[j] && j < i)
	{
		s2[j] = s1[j];
		j++;
	}
	s2[j] = '\0';
	return (s2);
}
