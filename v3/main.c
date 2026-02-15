/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masilva- <masilva-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/15 09:00:49 by masilva-@st       #+#    #+#             */
/*   Updated: 2026/02/15 13:25:46 by masilva-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int main(int ac, char **av)
{
    //t_dict  **dict;

    (void)av;
    if (ac > 3 || ac == 1)
    {
        ft_error(1);
        return (1);
    }
    init_dict("numbers.dict");

}
