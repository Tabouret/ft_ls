/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollier <pollier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/23 13:24:15 by gfernand          #+#    #+#             */
/*   Updated: 2015/10/24 11:27:48 by pollier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_cw(char const *s, char c)
{
	int		count;
	int		in_word;

	in_word = 0;
	count = 0;
	while (*s)
	{
		if (in_word && *s == c)
			in_word = 0;
		if (!in_word && *s != c)
		{
			in_word = 1;
			count++;
		}
		s++;
	}
	return (count);
}

static int		ft_sublen(const char *s, char c)
{
	int		len;

	len = 0;
	while (*s != c && *s != '\0')
	{
		len++;
		s++;
	}
	return (len);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**u;
	int		word_count;
	int		index;

	if (!s || !*s)
		return (NULL);
	index = 0;
	word_count = ft_cw(s, c);
	if (!(u = (char **)ft_strnew(sizeof(*u) * (ft_cw((const char *)s, c) + 2))))
		return (NULL);
	while (word_count--)
	{
		while (*s && *s == c)
			s++;
		u[index] = ft_strsub((const char *)s, 0, ft_sublen((const char *)s, c));
		if (u[index] == NULL)
			return (NULL);
		s = s + ft_sublen(s, c);
		index++;
	}
	u[index] = NULL;
	return (u);
}
