/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   target.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollier <pollier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/14 04:31:43 by pollier           #+#    #+#             */
/*   Updated: 2015/12/14 09:15:50 by pollier          ###   ########.fr       */
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

char				*to_path(char const *prefix, char *suffix, size_t namelen)
{
	char			**lol;
	char			*retour;

	lol = ft_memnew(sizeof(char**) * 3);
	lol[0] = ft_strdup(prefix);
	lol[1] = ft_strndup(suffix, namelen);
	retour = ft_implode(lol, "/");
	if ( lol && lol[0] && lol[1])
	{
		free(lol[0]);
		free(lol[1]);
		free(lol);
	}
	return (retour);
}

static t_target		*target_is_dir(char const *name, t_params *options)
{
	struct dirent	*d;
	DIR				*dir;
	t_target		*start;
	char			*tmp;

	dir = opendir(name);
	start = NULL;
	if (dir == NULL)
	return (NULL);
	while ((d = readdir(dir)) != NULL)
	{
		if (d->d_name[0] != '.' || options->a_dot)
		{
			tmp = to_path(name, d->d_name, d->d_namlen);
			start = create_target(start, tmp, options, options->r_rec);
			free(tmp);
		}
	}
	closedir(dir);
	free(d);
	return (start);

}

t_target		*create_target(t_target *start, char const *name, t_params *options, int flag)
{
	t_target	*new;

	new = ft_memnew(sizeof(t_target));
	new->name = ft_strdup(name);
	new->stats = ft_memnew(sizeof(struct stat));
	if (start)
	ft_last_target(start)->next = new;
	if (lstat(new->name, new->stats))
	ft_ls_error(ERROR_LSTAT, name);
	if (S_ISDIR(new->stats->st_mode) && flag)
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
				start = create_target(start, argv[i], options, 1);
			}
			i++;
		}
	}
	return (start);
}
