/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollier <pollier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/12 22:05:18 by pollier           #+#    #+#             */
/*   Updated: 2014/11/16 12:45:29 by pollier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	unsigned int	a;
	unsigned int	b;
	unsigned int	c;

	a = 0;
	b = 0;
	c = 0;
	if (!*s2)
		return ((char *)s1);
	while (s1[a] && a < n && s2[b])
	{
		while (s1[a] && s2[b] && (s1[a] == s2[b]) && a < n)
		{
			a++;
			b++;
			if (!s2[b])
				return ((char *)(s1 + c));
		}
		a++;
		c++;
	}
	return (NULL);
}
