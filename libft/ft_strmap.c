/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollier <pollier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/10 22:45:17 by pollier           #+#    #+#             */
/*   Updated: 2014/11/16 12:43:23 by pollier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	unsigned int		i;
	char				*unicorn;

	i = 0;
	unicorn = malloc(sizeof(char) * ft_strlen(s) + 1);
	while (s[i])
	{
		unicorn[i] = (*f)(s[i]);
		i++;
	}
	return (unicorn);
}
