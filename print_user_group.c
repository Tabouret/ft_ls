/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_user_group.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollier <pollier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/14 06:05:58 by pollier           #+#    #+#             */
/*   Updated: 2015/12/14 06:11:17 by pollier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void			print_user(struct stat *stats)
{
	struct passwd	*pass_info;

	if (!(pass_info = getpwuid(stats->st_uid)))
	{
		ft_putstr("Erreur");
	}
	else
	{
		ft_putstr(pass_info->pw_name);
	}
}

static void			print_group(struct stat *stats)
{
	struct group	*group_info;

	if (!(group_info = getgrgid(stats->st_gid)))
	{
		ft_putstr("Erreur");
	}
	else
	{
		ft_putstr(group_info->gr_name);
		ft_putchar('\t');
	}
}

void				print_user_group(struct stat *stats)
{
	print_user(stats);
	ft_putchar('\t');
	print_group(stats);
	ft_putchar('\t');
}
