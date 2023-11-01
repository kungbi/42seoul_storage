/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woonshin <woonshin@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 21:45:09 by woonshin          #+#    #+#             */
/*   Updated: 2023/11/01 11:17:50 by woonshin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static t_flexstr	*line;
	size_t						n;
	size_t						i;
	char							buffer[BUFFER_SIZE];
	char							*result;

	if (line == NULL)
		if (flexstr_new(&line, BUFFER_SIZE) != 0)
			return (NULL);
	n = read(fd, buffer, BUFFER_SIZE);
	while (0 < n)
	{
		if (flex_strcat(&line, buffer, n) != 0)
		{
			flexstr_free(&line, 1);
			return (NULL);
		}
		result = flexstr_slicenpop(line);
		if (result != NULL)
			return (result);
		n = read(fd, buffer, BUFFER_SIZE);
	}
	if (0 < line->cursor)
	{
		result = (char *)malloc(sizeof(char) * (line->cursor + 1));
		i = 0;
		while (i < line->cursor)
		{
			result[i] = line->str[i];
			i++;
		}
		result[i] = '\0';
		flexstr_free(&line, 1);
		return (result);
	}
	return (NULL);
}

int	get_line_length(char *str, size_t n, size_t *i)
{
	*i = 0;
	while (*i < n)
	{
		if (str[*i] == '\n')
		{
			(*i)++;
			return (0);
		}
		(*i)++;
	}
	return (-1);
}
