/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollier <pollier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/14 05:06:31 by pollier           #+#    #+#             */
/*   Updated: 2015/12/14 09:31:02 by pollier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

// void		print_dir(target, options)
// {
//
// }

void		print_targets(t_target *target, t_params *options)
{
	if (target)
	{
		if (options->r_rev)
			print_targets(target->next, options);
		if (options->l_lst)
			ft_print_data_l(options, target->stats);
		ft_putendl(target->name);
		ft_putchar('\n');
		if (target->dir)
		{
			ft_putstr(target->name);
			print_targets(target->dir, options);
	}
		if (!options->r_rev)
			print_targets(target->next, options);
	}
}
