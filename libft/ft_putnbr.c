/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollier <pollier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 14:09:10 by pollier           #+#    #+#             */
/*   Updated: 2015/11/07 09:28:46 by pollier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr(int n)
{
	char *m;

	m = ft_itoa(n);
	if (m)
	{
		write(1, m, ft_strlen(m));
		free(m);
	}
}
