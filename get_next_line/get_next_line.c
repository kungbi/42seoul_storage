/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woonshin <woonshin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 21:45:09 by woonshin          #+#    #+#             */
/*   Updated: 2023/11/04 18:37:31 by woonshin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	size_t				n;
	char				buffer[BUFFER_SIZE];
	static t_flexstr	*flexstr;
	char				*result;

	if (fd < 0)
		return (NULL);
	if (flexstr == NULL && flexstr_new(&flexstr, BUFFER_SIZE) != 0)
		return (NULL);
	if (flexstr_linepop(&flexstr, &result) < 0)
		return (NULL);
	if (result != NULL)
		return (result);
	n = read(fd, buffer, BUFFER_SIZE);
	if (BUFFER_SIZE < n)
	{
		flexstr_free(&flexstr, -1);
		return (NULL);
	}
	while (0 < n)
	{
		if (flexstr_append(&flexstr, buffer, n) != 0)
			return (NULL);
		if (flexstr_linepop(&flexstr, &result) < 0)
			return (NULL);
		if (result != NULL)
			return (result);
		n = read(fd, buffer, BUFFER_SIZE);
	}
	if (0 <flexstr->cursor)
	{
		flexstr->nl_flag = 1;
		flexstr->nl_i = flexstr->cursor;
	}
	flexstr_linepop(&flexstr, &result);
	flexstr_free(&flexstr, -1);
	if (result != NULL)
		return (result);
	return (NULL);
}

int	flexstr_free(t_flexstr **flexstr, int exit_num)
{
	t_flexstr	*flexstr_copy;

	if (*flexstr == NULL)
		return (exit_num);
	flexstr_copy = *flexstr;
	free(flexstr_copy->str);
	free(flexstr_copy);
	*flexstr = NULL;
	return (exit_num);
}
