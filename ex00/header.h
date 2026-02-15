/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masilva-@student.42lisboa.com <masilva-    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/14 18:16:20 by masilva-@st       #+#    #+#             */
/*   Updated: 2026/02/15 08:37:34 by masilva-@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>

#define BUFFER_SIZE 100

typedef struct s_dict
{
	int				index;
	char 			*key;
	char 			*value;
	struct s_dict 	*next;
}   				t_dict;

#endif