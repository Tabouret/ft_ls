/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollier <pollier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 19:46:55 by pollier           #+#    #+#             */
/*   Updated: 2014/11/14 06:46:24 by pollier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strcmp(const char *s1, const char *s2)
{
	unsigned int	index;

	index = 0;
	while (s1[index] && s2[index] && s1[index] == s2[index])
		index++;
	if (s1[index] != s2[index])
		return ((int)((unsigned char)s1[index] - (unsigned char)s2[index]));
	return (0);
}
