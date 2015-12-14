/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollier <pollier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/14 03:57:05 by pollier           #+#    #+#             */
/*   Updated: 2015/12/14 05:11:46 by pollier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int					main(int argc, char const *argv[])
{
	t_params		*options;
	t_target		*targets;

	options = ft_get_options(argc, argv);
	targets = ft_get_targets(int argc, char const *argv[]);
	process_targets(targets);
	return (0);
}
