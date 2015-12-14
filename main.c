/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollier <pollier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/14 03:57:05 by pollier           #+#    #+#             */
/*   Updated: 2015/12/14 05:37:50 by pollier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void				ft_ls_error(int error_code)
{
	ft_putstr("Erreur : ");
	ft_putnbr(error_code);
	ft_putchar('\n');
}

int					main(int argc, char const *argv[])
{
	t_params		*options;
	t_target		*targets;

	options = ft_get_options(argc, argv);
	targets = ft_get_targets(argc, argv);
	process_targets(targets, options);
	return (0);
}
