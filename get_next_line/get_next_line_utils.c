/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woonshin <woonshin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 21:45:25 by woonshin          #+#    #+#             */
/*   Updated: 2023/11/03 13:55:56 by woonshin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	flexstr_slicenpop(t_flexstr *line, char **output)
{
	size_t	output_len;
	size_t	i;

	*output = NULL;
	if (get_line_length(line->str, line->cursor, &output_len) != 0)
		return (1);
	*output = (char *)malloc(sizeof(char) * (output_len + 1));
	if (*output == NULL)
	{
		flexstr_free(&line);
		return (-1);
	}
	i = 0;
	while (i < output_len)
	{
		(*output)[i] = line->str[i];
		i++;
	}
	(*output)[output_len] = '\0';
	flexstr_npop(line, output_len);
	return (0);
}

int	flexstr_npop(t_flexstr *line, size_t n)
{
	size_t	i;

	i = 0;
	while (i < line->size)
	{
		if (n + i < line->size)
			line->str[i] = line->str[n + i];
		else
			line->str[i] = '\0';
		i++;
	}
	line->cursor = line->cursor - n;
	return (0);
}

int	flex_strcat(t_flexstr **line, char *src, size_t strlen)
{
	size_t	i;

	if ((*line)->size <= (*line)->cursor + strlen + 1)
	{
		if (flexstr_extend(line) != 0)
			return (-1);
	}
	i = 0;
	while (i < strlen)
		(*line)->str[(*line)->cursor++] = src[i++];
	return (0);
}

int	flexstr_extend(t_flexstr **line)
{
	t_flexstr	*new_line;
	size_t		i;

	if (*line == NULL)
		return (-1);
	if (flexstr_new(&new_line, (*line)->size * 2))
		return (-1);
	new_line->size = (*line)->size * 2;
	new_line->cursor = (*line)->cursor;
	i = 0;
	while (i < (*line)->cursor)
	{
		new_line->str[i] = (*line)->str[i];
		i++;
	}
	flexstr_free(line);
	*line = new_line;
	return (0);
}

int	flexstr_new(t_flexstr **flex_str, size_t size)
{
	size_t	i;

	*flex_str = (t_flexstr *)malloc(sizeof(t_flexstr) * 1);
	if (*flex_str == NULL)
	{
		flexstr_free(flex_str);
		return (-1);
	}
	(*flex_str)->str = (char *)malloc(sizeof(char) * size);
	if ((*flex_str)->str == NULL)
	{
		flexstr_free(flex_str);
		free((*flex_str)->str);
		return (-1);
	}
	i = 0;
	while (i < size)
	{
		(*flex_str)->str[i] = 0;
		i++;
	}
	(*flex_str)->size = size;
	(*flex_str)->cursor = 0;
	return (0);
}
