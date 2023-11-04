/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woonshin <woonshin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 21:45:17 by woonshin          #+#    #+#             */
/*   Updated: 2023/11/04 17:38:30 by woonshin         ###   ########.fr       */
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
	int		nl_flag;
	size_t	nl_i;
}	t_flexstr;

typedef struct s_flexstr_lst
{
	int			fd;
	t_flexstr	*line;
}	t_flexstr_lst;

int	flexstr_new(t_flexstr **flexstr, size_t size);
int	flexstr_append(t_flexstr **flexstr, char *src, size_t strlen);
int	flexstr_getline(t_flexstr **flexstr, char **output);
int	flexstr_linepop(t_flexstr **flexstr, char **output);
int	flexstr_extend(t_flexstr **flexstr);
int	flexstr_free(t_flexstr **flexstr, int exit_num);

#endif