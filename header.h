/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masilva-@student.42lisboa.com <masilva-    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/14 18:16:20 by masilva-@st       #+#    #+#             */
/*   Updated: 2026/02/14 18:45:57 by masilva-@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

typedef struct s_key
{
    char *nbr;
    char *str;
}   t_key;

typedef struct s_dict
{
    t_key *key;
    t_key *next;
}   t_dict;

