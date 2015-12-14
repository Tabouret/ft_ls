/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollier <pollier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 23:43:33 by pollier           #+#    #+#             */
/*   Updated: 2014/11/12 23:37:58 by pollier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char	a;
	void	*b;

	if (n)
	{
		a = *(char *)src;
		b = ft_memmove(dest + 1, src + 1, n - 1);
		*(char *)dest = a;
	}
	b = dest;
	return (b);
}
