/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masilva-@student.42lisboa.com <masilva-    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/15 08:59:39 by masilva-@st       #+#    #+#             */
/*   Updated: 2026/02/15 08:59:41 by masilva-@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

size_t	ft_nl_strlen(const char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\n')
		i++;
	return (i);
}

char	*ft_strjoin(char *line, char *buff)
{
	char	*new;
	size_t	i;
	size_t	j;

	new = malloc(ft_nl_strlen(line) + ft_nl_strlen(buff) + 1);
	if (!new)
		return (NULL);
	i = 0;
	j = 0;
	while (line && line[i])
	{
		new[i] = line[i];
		i++;
	}
	if (line)
		free(line);
	while (buff[j])
	{
		new[i++] = buff[j];
		if (buff[j++] == '\n')
			break ;
	}
	new[i] = '\0';
	return (new);
}

int	ft_clean(char *buff)
{
	int		i;
	int		j;
	int		flag;

	flag = 0;
	i = 0;
	j = 0;
	while (buff[i])
	{
		if (flag == 1)
			buff[j++] = buff[i];
		if (buff[i] == '\n')
			flag = 1;
		buff[i++] = '\0';
	}
	return (flag);
}

char	*dict_line(int fd)
{
	char        buff[BUFFER_SIZE];
	char		*line;
	int			i;

	i = 0;
	if (BUFFER_SIZE < 1 || fd < 0)
	{
		while (buff[i])
			buff[i++] = 0;
		return (NULL);
	}
	line = NULL;
	while (buff[0] || read(fd, buff, BUFFER_SIZE) > 0)
	{
		line = ft_strjoin(line, buff);
		if (ft_clean(buff))
			break ;
	}
	return (line);
}
