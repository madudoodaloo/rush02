/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_dict.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masilva- <masilva-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/15 09:00:40 by masilva-@st       #+#    #+#             */
/*   Updated: 2026/02/15 14:30:47 by masilva-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

t_dict  *new_entry(char *line)
{
    int i;
    int len;
    char *key;
    char *value;
    t_dict  *new;

    i = 0;
    while (line[i] && !ft_isspace(line[i]) && line[i] != ':')
        i++;
    key = ft_strndup(line, i);
    while (line[i] && (ft_isspace(line[i]) || line[i] == ':'))
        i++;
    len = ft_strlen(line + i);
    value = ft_strndup(line + i, len - 1);
    new = ft_lstnew(&key, &value);
    return (new);
}

t_dict  **parse_dict(int fd)
{
    char *line;
    t_dict **head;
    t_dict *new;

    head = malloc(sizeof(t_dict *));
    if (!head)
        return (NULL);
    *head = NULL;
    while (1)
    {
        line = dict_line(fd);
        printf("%s", line);
        if (!line)
            break;
        if (ft_strcmp(line, "\n") != 0)
        {
            new = new_entry(line);
            if (!new)
                ft_error(4);
            ft_lstadd_back(head, new);
        }
        print_dict(head);
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
