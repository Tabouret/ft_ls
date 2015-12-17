/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollier <pollier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/14 05:06:31 by pollier           #+#    #+#             */
/*   Updated: 2015/12/17 18:50:55 by pollier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		print_filename(char *str)
{
	size_t	len;

	len = ft_strlen(str);
	while (len && str[len] != '/')
	{
		len--;
	}
	ft_putendl(str + len + ((str[len] == '/') ? 1 : 0));
}

void		print_targets(t_target *target, t_params *options)
{
	if (target)
	{
		if (options->r_rev)
		{
			print_targets(target->next, options);
			if (target->dir && (target->name[0] != '.' || options->a_dot))
			{
				ft_putchar('\n');
				ft_putstr(target->name);
				ft_putendl(":");
			}
		}
		if (options->l_lst)
		{
			ft_print_data_l(options, target->stats);
		}
		if(!target->dir)
		{
			print_filename(target->name);
		}
		if (target->dir)
		{
			if (!options->r_rev && (target->name[0] != '.' || options->a_dot))
			{
				ft_putchar('\n');
				ft_putstr(target->name);
				ft_putendl(":");
			}
			print_targets(target->dir, options);
		}
		if (!options->r_rev)
		{
			print_targets(target->next, options);
		}
	}
}
