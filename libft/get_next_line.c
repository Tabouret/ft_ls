/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollier <pollier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/22 10:29:47 by pollier           #+#    #+#             */
/*   Updated: 2015/09/30 03:00:34 by pollier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	char	*ft_join(char *s1, char *s2)
{
	size_t		a;
	size_t		b;
	char		*d;

	a = 0;
	b = 0;
	if (s1)
		a = ft_strlen(s1);
	if (s2)
		b = ft_strlen(s2);
	d = ft_strnew(a + b + 1);
	if (a)
		ft_memcpy(d, s1, a);
	if (b)
		ft_memcpy(d + a, s2, b);
	free(s1);
	ft_bzero(s2, BUFF_SIZE + 1);
	return (d);
}

static	ssize_t	ft_eol(char *buff)
{
	ssize_t		a;

	a = 0;
	while (buff[a] != '\n' && buff[a])
		a++;
	if (buff[a] == '\n')
	{
		buff[a] = '\0';
		return (a);
	}
	else
		return (-1);
}

static	int		ft_check(char **save, char **r_buff, char **line)
{
	ssize_t		eol;
	char		*a;

	*save = ft_join(*save, *r_buff);
	eol = ft_eol(*save);
	if (eol > -1)
	{
		*line = ft_strdup(*save);
		a = *save;
		*save = ft_strdup(*save + eol + 1);
		free(a);
		return (1);
	}
	return (0);
}

int				get_next_line(int const fd, char **line)
{
	char			*r_buff;
	static	char	*save = NULL;
	int				r_read;
	int				r_val;

	r_buff = ft_strnew(BUFF_SIZE + 1);
	if (fd < 0 || fd == 1 || (r_read = read(fd, r_buff, 0)) < 0)
		return (-1);
	r_val = ft_check(&save, &r_buff, line);
	if (r_val == 1)
		return (1);
	while ((r_read = read(fd, r_buff, BUFF_SIZE)) > 0)
	{
		r_val = ft_check(&save, &r_buff, line);
		if (r_val == 1)
			return (1);
	}
	if (r_read == 0)
		*line = ft_strdup(save);
	free(r_buff);
	ft_strdel(&save);
	return (r_read);
}
