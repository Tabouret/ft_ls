/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollier <pollier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/09 05:19:25 by pollier           #+#    #+#             */
/*   Updated: 2015/05/08 21:02:46 by pollier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	size_t	size;

	if (!s1 || !s2 || !n)
		return (s1);
	size = ft_strlen(s1);
	ft_memcpy(s1 + size, s2, n);
	s1[size + n + 1] = '\0';
	return (s1);
}
