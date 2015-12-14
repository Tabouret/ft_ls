/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollier <pollier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/11 00:13:09 by pollier           #+#    #+#             */
/*   Updated: 2015/11/07 04:41:19 by pollier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_realloc(void **src, size_t n_length, size_t old_length)
{
	void	*new;

	new = ft_memnew(n_length);
	new = ft_memcpy(new, src, old_length);
	ft_bzero(new + old_length, n_length - old_length);
	free(*src);
	*src = new;
}
