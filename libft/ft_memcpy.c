/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollier <pollier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 16:02:28 by pollier           #+#    #+#             */
/*   Updated: 2014/11/16 12:35:19 by pollier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char			*str_dst;
	const char		*str_src;
	unsigned int	i;

	str_dst = (char *)dst;
	str_src = (const char *)src;
	i = 0;
	while (n--)
	{
		str_dst[i] = str_src[i];
		i++;
	}
	return (dst);
}
