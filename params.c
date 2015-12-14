/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   params.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollier <pollier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/14 05:05:29 by pollier           #+#    #+#             */
/*   Updated: 2015/12/14 05:49:03 by pollier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void			ft_setopt(char const *opt, t_params *options)
{
	size_t			i;

	i = 0;
	while (opt[i])
	{
		if (opt[i] == 'l')
			options->l_lst = 1;
		else if (opt[i] == 'R')
			options->r_rec = 1;
		else if (opt[i] == 'a')
			options->a_dot = 1;
		else if (opt[i] == 'r')
			options->r_rev = 1;
		else if (opt[i] == 't')
			options->t_time_sort = 1;
		else if (opt[i] == 'h')
			options->h_human = 1;
		else
			ft_ls_error(ERROR_BAD_OPTION);
		i++;
	}
}

t_params		*ft_get_options(int argc, char const *argv[])
{
	int			i;
	t_params	*options;

	i = 1;
	options = ft_memnew(sizeof(t_params));
	if (argc > 1)
	{
		while (i < argc && argv[i])
		{
			if (argv[i][0] == '-')
			{
				ft_setopt(argv[i], options);
			}
			i++;
		}
	}
	return (options);
}
