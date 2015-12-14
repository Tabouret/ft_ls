/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollier <pollier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/23 16:59:58 by pollier           #+#    #+#             */
/*   Updated: 2015/01/27 12:40:45 by pollier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t size)
{
	t_list	*new_element;

	new_element = malloc(sizeof(t_list));
	if (!content)
	{
		new_element->content = NULL;
		new_element->size = 0;
	}
	else
	{
		new_element->size = size;
		if (!(new_element->content = malloc(size)))
			return (NULL);
		ft_memcpy(new_element->content, content, size);
	}
	new_element->next = NULL;
	return (new_element);
}
