/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollier <pollier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/10 22:50:45 by pollier           #+#    #+#             */
/*   Updated: 2014/11/16 12:43:32 by pollier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int		i;
	char				*unicorn;

	i = 0;
	unicorn = malloc(sizeof(char) * ft_strlen(s) + 1);
	while (s[i])
	{
		unicorn[i] = (*f)(i, s[i]);
		i++;
	}
	return (unicorn);
}
