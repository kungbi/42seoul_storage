/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woonshin <woonshin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 21:45:17 by woonshin          #+#    #+#             */
/*   Updated: 2023/11/03 13:55:59 by woonshin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

# include <unistd.h>
# include <stdlib.h>

# include <stdio.h>
# include <fcntl.h>

char	*get_next_line(int fd);

typedef struct s_flexstr
{
	char	*str;
	size_t	size;
	size_t	cursor;
}	t_flexstr;

typedef struct s_flexstr_lst
{
	int			fd;
	t_flexstr	*line;
}	t_flexstr_lst;

int		flex_strcat(t_flexstr **line, char *src, size_t strlen);
int		flexstr_extend(t_flexstr **line);
int		flexstr_new(t_flexstr **flex_str, size_t size);
int		flexstr_free(t_flexstr **flex_str);
int		get_line_length(char *str, size_t n, size_t *i);
int		flexstr_slicenpop(t_flexstr *line, char **output);
int		flexstr_npop(t_flexstr *line, size_t n);

#endif