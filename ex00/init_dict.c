/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_dict.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masilva-@student.42lisboa.com <masilva-    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/15 09:00:40 by masilva-@st       #+#    #+#             */
/*   Updated: 2026/02/15 11:33:09 by masilva-@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"



t_dict  *new_entry(char *line)
{
    int i;
    char *key;
    char *value;
    t_dict  *new;

    i = 0;
    while (line[i] && !ft_isspace(line[i]))
        i++;
    key = ft_strndup(line, i);
    while (line[i] && (ft_isspace(line[i]) || line[i] == ':'))
        i++;
    value = ft_strndup(line + i, ft_strlen(line + i - 1));
    new = ft_lstnew(key, value);
    printf("line: %s", line);

    return (new);
}

t_dict  **parse_dict(int fd)
{
    char *line;
    t_dict **head;
    t_dict *new;

    new = NULL;
    head = NULL;
    line = dict_line(fd);    
    while (line != NULL)
    {
        line = dict_line(fd);
        if (ft_strcmp(line, "\n") != 0)
        {
            new = new_entry(line);
            if (!new)
                ft_error(4);
            ft_lstadd_back(head, new);
        }
        free(line);
    }
    return (head);
}

t_dict  **init_dict(char *filename)
{
    int fd;
    t_dict **head_dict;

    fd = open(filename, O_RDONLY);
    if (fd == -1)
    {
        ft_error(2);
        return (NULL);
    }
    head_dict = parse_dict(fd);
    close(fd);
    if (!head_dict)
        ft_error(3);
    return (head_dict);
}
