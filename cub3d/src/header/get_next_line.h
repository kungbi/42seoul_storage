/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woonshin <woonshin@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 21:45:17 by woonshin          #+#    #+#             */
/*   Updated: 2024/09/25 14:43:07 by woonshin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

typedef struct s_flexstr
{
	char	*str;
	size_t	size;
	size_t	cursor;
	int		nl_flag;
	size_t	nl_i;
}	t_flexstr;

typedef struct s_flexlst
{
	int					fd;
	t_flexstr			*flexstr;
	struct s_flexlst	*next;
}	t_flexlst;

char		*get_next_line(int fd);
int			flexstr_new(t_flexstr **flexstr, size_t size);
int			flexstr_append(t_flexstr **flexstr, char *src, size_t strlen);
int			flexstr_getline(t_flexstr **flexstr, char **output);
int			flexstr_linepop(t_flexstr **flexstr, char **output, size_t i);
int			flexstr_extend(t_flexstr **flexstr);
int			flexstr_free(t_flexstr **flexstr, int exit_num);
t_flexlst	*flexlst_push(t_flexlst **flexlst, int fd);
int			flexlst_getline(t_flexlst *flexlst, char **output);
char		*flexlst_clear(t_flexlst **flexlst, int fd);

#endif