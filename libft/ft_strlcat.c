/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollier <pollier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/09 05:27:00 by pollier           #+#    #+#             */
/*   Updated: 2014/11/13 03:16:22 by pollier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	unsigned int	a;
	unsigned int	b;
	unsigned int	c;

	c = 0;
	a = ft_strlen(dst);
	b = ft_strlen(src) + a;
	if (size <= a || !size || !dst || !src)
		return (size + (b - a));
	while (a < size)
		dst[a++] = src[c++];
	dst[--a] = '\0';
	return (b);
}
