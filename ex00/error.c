/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masilva-@student.42lisboa.com <masilva-    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/15 09:00:31 by masilva-@st       #+#    #+#             */
/*   Updated: 2026/02/15 09:00:33 by masilva-@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	ft_free_and_exit(t_dict *dict)
{
	return ;
}

int ft_error(int error)
{
	if (error == 1)
		write(2, "./rush-02 [dict.txt] nbr\n", 25);
	else if (error == 2)
		write(2, "Couldn't read base dictionary\n", 30);
	else if (error == 3)
		write(2, "Malloc error occured\n", 21);
	else if (error == 4)
		write(2, "Dict Error\n", 11);
	return (error);
}