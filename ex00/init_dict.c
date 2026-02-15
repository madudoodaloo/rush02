/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_dict.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masilva- <masilva-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/15 09:00:40 by masilva-@st       #+#    #+#             */
/*   Updated: 2026/02/15 10:30:54 by masilva-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int ft_isspace(char c)
{
    if (c == ' ' || (c >= 9 && c <= 13))
        return (1);
    return (0);
}

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char    *ft_strndup(char *src, size_t length)
{
	char	*cpy;
	size_t	i;

	i = 0;
	cpy = (char *)malloc(sizeof(char) * (length + 1));
	if (!cpy)
		return (NULL);
	while (i < length)
	{
		cpy[i] = src[i];
		i++;
	}
	cpy[i] = '\0';
	return (cpy);
}

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
    return (new);
}

t_dict  **parse_dict(int fd)
{
    char *line;
    t_dict *head;
    t_dict *new;

    new = NULL;
    head = NULL;
    while (line != NULL)
    {
        line = dict_line(fd);
        if (ft_strcmp(line, "\n") != 0)
        {
            new = new_entry(line);
            if (!new)
                ft_error(4);
            head = ft_lst_addback(&head, new);
        }
        free(line);
    }
}

t_dict  *init_dict(char *filename)
{
    int fd;
    t_dict *head_dict;

    fd = open(filename, O_RDONLY);
    if (fd == -1)
    {
        ft_error(2);
        return ;
    }
    head_dict = parse_dict(fd);
    close(fd);
    if (!head_dict)
        ft_error(3);
    return (head_dict);
}
