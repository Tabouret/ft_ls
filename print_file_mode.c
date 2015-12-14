/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_file_mode.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollier <pollier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/14 06:05:58 by pollier           #+#    #+#             */
/*   Updated: 2015/12/14 06:08:00 by pollier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void			print_type_st_mode(struct stat *stats)
{
	if (S_ISDIR(stats->st_mode))
	ft_putchar('d');
	else if (S_ISBLK(stats->st_mode))
	ft_putchar('b');
	else if (S_ISCHR(stats->st_mode))
	ft_putchar('c');
	else if (S_ISFIFO(stats->st_mode))
	ft_putchar('p');
	else if (S_ISREG(stats->st_mode))
	ft_putchar('-');
	else if (S_ISLNK(stats->st_mode))
	ft_putchar('l');
	else if (S_ISSOCK(stats->st_mode))
	ft_putchar('s');
}

static void			print_rwx_user(struct stat *stats)
{
	if (stats->st_mode & S_IRUSR)
	ft_putchar('r');
	else
	ft_putchar('-');
	if (stats->st_mode & S_IWUSR)
	ft_putchar('w');
	else
	ft_putchar('-');
	if (stats->st_mode & S_IXUSR)
	ft_putchar('x');
	else
	ft_putchar('-');
}
static void			print_rwx_group(struct stat *stats)
{
	if (stats->st_mode & S_IRGRP)
	ft_putchar('r');
	else
	ft_putchar('-');
	if (stats->st_mode & S_IWGRP)
	ft_putchar('w');
	else
	ft_putchar('-');
	if (stats->st_mode & S_IXGRP)
	ft_putchar('x');
	else
	ft_putchar('-');
}

static void			print_rwx_other(struct stat *stats)
{
	if (stats->st_mode & S_IROTH)
	ft_putchar('r');
	else
	ft_putchar('-');
	if (stats->st_mode & S_IWOTH)
	ft_putchar('w');
	else
	ft_putchar('-');
	if (stats->st_mode & S_IXOTH)
	ft_putchar('x');
	else
	ft_putchar('-');
}

void				print_file_mode(struct stat *stats)
{
	print_type_st_mode(stats);
	print_rwx_user(stats);
	print_rwx_group(stats);
	print_rwx_other(stats);
}
