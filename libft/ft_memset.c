/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollier <pollier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 12:36:12 by pollier           #+#    #+#             */
/*   Updated: 2014/11/16 12:32:58 by pollier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	unicorn;
	unsigned int	pegasus;
	char			*pony;

	unicorn = (unsigned char)c;
	pegasus = 0;
	pony = (char*)b;
	while (pegasus < len)
	{
		pony[pegasus] = unicorn;
		pegasus++;
	}
	return (b);
}
