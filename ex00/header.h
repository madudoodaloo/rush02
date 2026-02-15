/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masilva- <masilva-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/14 18:16:20 by masilva-@st       #+#    #+#             */
/*   Updated: 2026/02/15 10:54:52 by masilva-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# define BUFFER_SIZE 100

typedef struct s_dict
{
	int				index;
	char 			*key;
	char 			*value;
	struct s_dict 	*next;
}   				t_dict;


/* dict_line.c */
size_t	ft_nl_strlen(const char *str);
char	*ft_strjoin(char *line, char *buff);
int	ft_clean(char *buff);
char	*dict_line(int fd);

/* error.c */
void	ft_free_and_exit(t_dict *dict);
int ft_error(int error);

int ft_isspace(char c);
size_t	ft_strlen(char *str);
char    *ft_strndup(char *src, size_t length);
t_dict  *new_entry(char *line);
t_dict  **parse_dict(int fd);
t_dict  *init_dict(char *filename);

/* lst_utils.c */
t_dict	*ft_lstlast(t_dict *lst);
t_dict	*ft_lstadd_back(t_dict **lst, t_dict *new);
t_dict	*ft_lstnew(char *key, char *value);

/* print_utils.c */
void print_dict(t_dict *dict);




#endif