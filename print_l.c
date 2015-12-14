/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_l.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollier <pollier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/14 05:55:46 by pollier           #+#    #+#             */
/*   Updated: 2015/12/14 06:13:20 by pollier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

/*
**		b		Block special file.
**		c		Character special file.
**		d		Directory.
**		l		Symbolic link.
**		s		Socket link.
**		p		FIFO.
**		-		Regular file.
*/

static void			print_hard_link(nlink_t size)
{
	char		stack[25];
	size_t		i;

	i = 0;
	ft_bzero(stack, 25);
	while (1)
	{
		stack[i] = '0' + size % 10;
		size /= 10;
		i++;
		if (!size)
		break ;
	}
	while (1)
	{
		ft_putchar(stack[i]);
		if (!i)
		break;
		else
		i--;
	}
}

static void			print_size(off_t size)
{
	char		stack[25];
	size_t		i;

	i = 0;
	ft_bzero(stack, 25);
	while (1)
	{
		stack[i] = '0' + size % 10;
		size /= 10;
		i++;
		if (!size)
		break ;
	}
	while (1)
	{
		ft_putchar(stack[i]);
		if (!i)
		break;
		else
		i--;
	}
}

static void			print_size_human(off_t size)
{
	char			i;

	i = 0;
	while (size / 1024)
	{
		size /= 1024;
		i++;
	}
	print_size(size);
	if (i == 1)
	ft_putstr('KiB');
	else if (i == 2)
	ft_putstr('MiB');
	else if (i == 3)
	ft_putstr('GiB');
	else if (i == 4)
	ft_putstr('TiB');
	else if (i == 5)
	ft_putstr('PiB');
}

static void			print_date(struct stat *stats)
{
	char	*date;

	date = ctime(&stats->st_mtimespec.tv_sec);
	date += 4;
	while (*date != '\n')
	{
		write(1, date, 1);
		date++;
	}
}

void				ft_print_data_l(t_params options, struct stat *stats)
{
	print_file_mode(stats);
	ft_putchar('\t');
	print_hard_link(stats->st_nlink);
	ft_putchar('\t');
	print_user_group(stats);
	ft_putchar('\t');
	if (meta->h_human)
		print_size_human(stats->st_size);
	else
		print_size(stats->st_size);
	ft_putchar('\t');
	print_date(stats);
	ft_putchar('\t');
}
