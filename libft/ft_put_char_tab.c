/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_char_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollier <pollier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/12 05:18:36 by pollier           #+#    #+#             */
/*   Updated: 2015/11/07 05:44:56 by pollier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_put_char_tab(char **tab)
{
	while (tab)
	{
		if (*tab)
		{
			ft_putstr(*tab);
			ft_putchar('\n');
			tab++;
		}
		else
		{
			break ;
		}
	}
}
