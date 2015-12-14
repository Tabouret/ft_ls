/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   target.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollier <pollier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/14 04:31:43 by pollier           #+#    #+#             */
/*   Updated: 2015/12/14 08:35:51 by pollier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_target			*ft_last_target(t_target *start)
{
	while (start && start->next)
	{
		start = start->next;
	}
	return (start);
}

static t_target		*target_is_dir(char const *name, t_params *options)
{
	
}

static t_target		*create_target(t_target *start, char const *name, t_params *options)
{
	t_target	*new;

	new = ft_memnew(sizeof(t_target));
	new->name = ft_strdup(name);
	new->stats = ft_memnew(sizeof(struct stat));
	if (start)
		ft_last_target(start)->next = new;
	if (lstat(new->name, new->stats))
		ft_ls_error(ERROR_LSTAT, name);
	if (ISDIR(new->stats->st_mode))
		new->dir = target_is_dir(name, options);
	return ((start) ? start : new);
}

t_target			*ft_get_targets(int argc, char const *argv[], t_params *options)
{
	int			i;
	t_target	*start;

	i = 1;
	start = NULL;
	if (argc > 1)
	{
		while (i < argc && argv[i])
		{
			if (argv[i][0] != '-')
			{
				start = create_target(start, argv[i], options);
			}
			i++;
		}
	}
	return (start);
}
