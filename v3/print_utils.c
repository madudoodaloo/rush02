/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masilva- <masilva-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/15 13:43:18 by masilva-          #+#    #+#             */
/*   Updated: 2026/02/15 13:43:18 by masilva-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	print_dict(t_dict **dict)
{
	t_dict	*current;

	if (!dict || !*dict)
	{
		printf("Dictionary is NULL or empty\n");
		return ;
	}
	printf("====== DICTIONARY CONTENT ======\n");
	current = *dict;
	while (current)
	{
		printf("Node address: %p\n", (void *)current);
		printf("  index: %d\n", current->index);
		printf("  key: %s\n", current->key ? current->key : "(null)");
		printf("  value: %s\n", current->value ? current->value : "(null)");
		printf("  next: %p\n", (void *)current->next);
		printf("--------------------------------\n");
		current = current->next;
	}
	printf("====== END OF DICTIONARY ======\n");
}