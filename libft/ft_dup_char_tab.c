/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dup_char_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollier <pollier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/15 22:51:08 by pollier           #+#    #+#             */
/*   Updated: 2015/10/15 23:03:49 by pollier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_dup_char_tab(char **tab)
{
	size_t		i;
	char		**copy;

	i = 0;
	while (tab && tab[i])
		i++;
	if (!(copy = ft_memnew(sizeof(char**) * i)))
		return (NULL);
	copy[i] = NULL;
	i = 0;
	while (tab && tab[i])
	{
		copy[i] = ft_strdup(tab[i]);
		i++;
	}
	return (copy);
}
