/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masilva-@student.42lisboa.com <masilva-    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/15 09:00:23 by masilva-@st       #+#    #+#             */
/*   Updated: 2026/02/15 09:00:24 by masilva-@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

t_dict	*ft_lstlast(t_dict *lst)
{
	t_dict	*end;

	end = lst;
	if (!lst)
		return (NULL);
	while (end->next != NULL)
		end = end -> next;
	return (end);
}

t_dict	*ft_lstadd_back(t_dict **lst, t_dict *new)
{
	t_dict	*end;
    int     index;

	if (*lst == NULL)
		*lst = new;
	else
	{
		end = ft_lstlast(*lst);
		end -> next = new;
        new -> index = end->index + 1;
	}
	return (*lst);
}

t_dict	*ft_lstnew(char *key, char *value)
{
	t_dict	*new;

	new = (t_dict *)malloc(sizeof(t_dict));
	if (!new)
		return (NULL);
	new->key = key;
    new->value = value;
    new->index = 0;
	new->next = NULL;
	return (new);
}