/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollier <pollier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/12 13:26:52 by pollier           #+#    #+#             */
/*   Updated: 2014/11/14 08:06:20 by pollier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned int	index;

	index = 0;
	while (s1[index] && s2[index] && s1[index] == s2[index] && index < n)
		index++;
	if (s1[index] != s2[index] && index < n)
		return ((int)((unsigned char)s1[index] - (unsigned char)s2[index]));
	return (0);
}
