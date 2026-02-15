/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masilva-@student.42lisboa.com <masilva-    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/15 09:00:49 by masilva-@st       #+#    #+#             */
/*   Updated: 2026/02/15 11:30:01 by masilva-@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int main(int ac, char **av)
{
    t_dict  **dict;

    (void)av;
    if (ac > 3 || ac == 1)
    {
        ft_error(1);
        return (1);
    }
    dict = init_dict("numbers.dict");
    if (dict)
    {
        
    }
    //parse do input dado e correr o prog
    print_dict(dict);
    //ft_free_and_exit();
}

//    if (ac == 3)
//    //    update_dict(av[1], dict);
//    else if (ac == 2 && ft_strcmp(av[1], "-") == 0)
//    //    ;
//    else if (ac == 2)
//    //    ;