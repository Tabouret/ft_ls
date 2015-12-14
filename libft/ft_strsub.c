/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollier <pollier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/10 23:04:12 by pollier           #+#    #+#             */
/*   Updated: 2015/10/09 06:36:35 by pollier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*str;
	int		index;

	if (!(str = ft_strnew(len + 1)))
		return (NULL);
	index = 0;
	while (len--)
	{
		str[index] = s[start + index];
		index++;
	}
	return (str);
}
