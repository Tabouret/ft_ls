/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollier <pollier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/14 05:06:31 by pollier           #+#    #+#             */
/*   Updated: 2015/12/14 07:44:29 by pollier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		print_targets(t_target *target, t_params *options)
{
	if (target)
	{
		if (options->r_rev)
			print_targets(target->next, options);
		if (options->l_lst)
			ft_print_data_l(options, target->stats);
		ft_putendl(target->name);
		if (!options->r_rev)
			print_targets(target->next, options);
	}
}
