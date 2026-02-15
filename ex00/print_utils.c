/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masilva-@student.42lisboa.com <masilva-    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/15 09:00:58 by masilva-@st       #+#    #+#             */
/*   Updated: 2026/02/15 09:01:00 by masilva-@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void print_dict(t_dict *dict)
{
    t_dict *temp;

    temp = dict;
    while (temp->next != NULL)
    {
        printf("[%d]%s:%s", temp->index, temp->key, temp->value);
        temp = temp->next;
    }

}