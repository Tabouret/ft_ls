/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollier <pollier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 17:05:21 by pollier           #+#    #+#             */
/*   Updated: 2014/11/16 12:47:42 by pollier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *s1, const char *s2, size_t n)
{
	unsigned int	size;

	if (!s1 || !s2)
		return (s1);
	size = ft_strlen(s2);
	if (size >= n)
		ft_memcpy(s1, s2, n);
	else
	{
		ft_memcpy(s1, s2, size);
		ft_memset(s1 + size, '\0', n - size);
	}
	return (s1);
}
