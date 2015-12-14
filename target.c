/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   target.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollier <pollier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/14 04:31:43 by pollier           #+#    #+#             */
/*   Updated: 2015/12/14 04:47:36 by pollier          ###   ########.fr       */
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

static t_target		*create_target(t_target *start, char const *name)
{
	t_target	*new;

	if (!start)
	{
		new = ft_memnew(sizeof(t_target));
		new->name = ft_strdup(name);
	}
	else
	{
		new = start;
		start = ft_last_target(start);
		start->next = ft_memnew(sizeof(t_target));
		start->next->name = ft_strdup(name);
	}
	return (new);
}

t_target			*ft_get_targets(int argc, char const *argv[])
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
				start = create_target(start, argv[i);
			}
			i++;
		}
	}
	return (start);
}
