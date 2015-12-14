/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollier <pollier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/09 07:21:15 by pollier           #+#    #+#             */
/*   Updated: 2015/10/24 11:26:52 by pollier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memnew(size_t size)
{
	char	*new;

	if (!(new = malloc(size)))
		return (NULL);
	ft_bzero(new, size);
	return (new);
}
