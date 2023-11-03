/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woonshin <woonshin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 21:45:09 by woonshin          #+#    #+#             */
/*   Updated: 2023/11/03 13:55:48 by woonshin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static t_flexstr	*line;
	size_t				n;
	size_t				i;
	char				buffer[BUFFER_SIZE];
	char				*result;

	if (fd < 0)
		return (NULL);
	if (line == NULL)
		if (flexstr_new(&line, BUFFER_SIZE) != 0)
		{
			flexstr_free(&line);
			return (NULL);
		}
	if (flexstr_slicenpop(line, &result) < 0)
	{
		flexstr_free(&line);
		return (NULL);
	}
	if (result != NULL)
		return (result);
	n = read(fd, buffer, BUFFER_SIZE);
	if (BUFFER_SIZE < n)
	{
		flexstr_free(&line);
		return (NULL);
	}
	while (0 < n)
	{
		if (flex_strcat(&line, buffer, n) != 0)
		{
			flexstr_free(&line);
			return (NULL);
		}
		if (flexstr_slicenpop(line, &result) < 0)
		{
			flexstr_free(&line);
			return (NULL);
		}
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
		flexstr_free(&line);
		return (result);
	}
	if (line != NULL)
		flexstr_free(&line);
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

int	flexstr_free(t_flexstr **flex_str)
{
	t_flexstr	*flex_str_copy;

	if (*flex_str == NULL)
		return (-1);
	flex_str_copy = *flex_str;
	*flex_str = NULL;
	free(flex_str_copy->str);
	free(flex_str_copy);
	return (0);
}
