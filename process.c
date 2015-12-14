/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollier <pollier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/14 05:06:31 by pollier           #+#    #+#             */
/*   Updated: 2015/12/14 06:21:45 by pollier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void process_targets(t_target *target, t_params *options)
{
	arg_debug(options);
	while (target && options)
	{
		if (options->l_lst)
			ft_print_data_l(options, target->stats);
		ft_putendl(target->name);
		target = target->next;
	}
}
