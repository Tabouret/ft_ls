/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_implode.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollier <pollier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/08 05:57:48 by pollier           #+#    #+#             */
/*   Updated: 2015/10/08 07:03:22 by pollier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_implode(char **pieces, char *glue)
{
	size_t		index[3];
	char		*total;

	index[0] = 0;
	index[1] = 0;
	if (pieces)
	{
		index[2] = (glue) ? ft_strlen(glue) : 0;
		while (pieces[index[0]])
		{
			index[1] += ft_strlen(pieces[index[0]++]) + index[2];
		}
		index[1] -= index[2];
		total = ft_strnew(index[1] + 1);
		index[0] = 0;
		while (pieces[index[0]])
		{
			total = (glue && index[0]) ? ft_strcat(total, glue) : total;
			total = ft_strcat(total, pieces[index[0]++]);
		}
		return (total);
	}
	return (NULL);
}
