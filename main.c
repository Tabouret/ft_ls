/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollier <pollier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/14 03:57:05 by pollier           #+#    #+#             */
/*   Updated: 2015/12/14 08:25:48 by pollier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void				ft_ls_error(int error_code, const char *opt)
{
	if (error_code == ERROR_BAD_OPTION)
	{
		ft_putstr("./ft_ls: illegal option -- ");
		ft_putstr((char*)opt);
		ft_putchar('\n');
		ft_putendl("usage: ./ft_ls: [-Ralrt]");
	}
	ft_putstr("Erreur : ");
	ft_putnbr(error_code);
	ft_putchar('\n');
	// exit(error_code);
}

void				arg_debug(t_params *options)
{
	if (options)
	{
		ft_putstr("\nHidden -a : ");
		ft_putstr((options->a_dot) ? "yes\n" : "no\n");
		ft_putstr("Recursive -R : ");
		ft_putstr((options->r_rec) ? "yes\n" : "no\n");
		ft_putstr("List -l : ");
		ft_putstr((options->l_lst) ? "yes\n" : "no\n");
		ft_putstr("Reverse -r : ");
		ft_putstr((options->r_rev) ? "yes\n" : "no\n");
		ft_putstr("Time sort : ");
		ft_putstr((options->t_time_sort) ? "yes\n" : "no\n");
	}
}

int					main(int argc, char const *argv[])
{
	t_params		*options;
	t_target		*targets;

	options = ft_get_options(argc, argv);
	targets = ft_get_targets(argc, argv, options);
	// if (!targets)
	// {
	// 	targets = ls_cur_dir(options);
	// }
	print_targets(targets, options);
	return (0);
}
