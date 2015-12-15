/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   target.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollier <pollier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/14 04:31:43 by pollier           #+#    #+#             */
/*   Updated: 2015/12/15 12:47:48 by pollier          ###   ########.fr       */
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
	if (lol && lol[0] && lol[1])
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
			start = cte_tar(start, tmp, options, options->r_rec);
			free(tmp);
		}
	}
	closedir(dir);
	free(d);
	return (start);
}

t_target		*cte_tar(t_target *s, char const *n, t_params *o, int f)
{
	t_target	*new;

	new = ft_memnew(sizeof(t_target));
	new->name = ft_strdup(n);
	new->stats = ft_memnew(sizeof(struct stat));
	if (s)
		ft_last_target(s)->next = new;
	if (lstat(new->name, new->stats))
		ft_ls_error(ERROR_LSTAT, n);
	if (S_ISDIR(new->stats->st_mode) && f)
		new->dir = target_is_dir(n, o);
	return ((s) ? s : new);
}

t_target		*ft_get_targets(int argc, char const *argv[], t_params *options)
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
				start = cte_tar(start, argv[i], options, 1);
			}
			i++;
		}
	}
	return (start);
}
