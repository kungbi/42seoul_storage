/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woonshin <woonshin@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 21:45:25 by woonshin          #+#    #+#             */
/*   Updated: 2024/01/19 17:13:00 by woonshin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	flexstr_new(t_flexstr **flexstr, size_t size)
{
	size_t	i;

	*flexstr = (t_flexstr *)malloc(sizeof(t_flexstr) * 1);
	if (*flexstr == NULL)
		return (flexstr_free(flexstr, -1));
	(*flexstr)->str = (char *)malloc(sizeof(char) * size);
	if ((*flexstr)->str == NULL)
		return (flexstr_free(flexstr, -1));
	i = 0;
	while (i < size)
	{
		(*flexstr)->str[i] = 0;
		i++;
	}
	(*flexstr)->cursor = 0;
	(*flexstr)->size = size;
	(*flexstr)->nl_flag = 0;
	return (0);
}

int	flexstr_append(t_flexstr **flexstr, char *src, size_t strlen)
{
	size_t		i;

	if ((*flexstr)->size <= (*flexstr)->cursor + strlen + 1
		&& flexstr_extend(flexstr) != 0)
		return (-1);
	i = 0;
	while (i < strlen)
	{
		if ((*flexstr)->nl_flag == 0 && src[i] == '\n')
		{
			(*flexstr)->nl_i = (*flexstr)->cursor + 1;
			(*flexstr)->nl_flag = 1;
		}
		(*flexstr)->str[(*flexstr)->cursor++] = src[i++];
	}
	return (0);
}

int	flexstr_extend(t_flexstr **flexstr)
{
	t_flexstr	*new_flexstr;
	size_t		i;

	if (flexstr_new(&new_flexstr, (*flexstr)->size * 2) != 0)
		return (flexstr_free(flexstr, -1));
	i = 0;
	while (i < new_flexstr->size)
	{
		if (i < (*flexstr)->cursor)
			new_flexstr->str[i]
				= (*flexstr)->str[i];
		else
			new_flexstr->str[i] = 0;
		i++;
	}
	new_flexstr->cursor = (*flexstr)->cursor;
	flexstr_free(flexstr, -1);
	*flexstr = new_flexstr;
	return (0);
}

int	flexstr_getline(t_flexstr **flexstr, char **output)
{
	size_t	i;

	*output = NULL;
	if (*flexstr == NULL)
		return (-1);
	if ((*flexstr)->nl_flag == 0)
		return (1);
	*output = (char *)malloc(sizeof(char) * ((*flexstr)->nl_i) + 1);
	if (*output == NULL)
		return (flexstr_free(flexstr, -1));
	i = 0;
	while (i < (*flexstr)->nl_i)
	{
		(*output)[i] = (*flexstr)->str[i];
		i++;
	}
	(*output)[i] = '\0';
	return (0);
}

int	flexstr_linepop(t_flexstr **flexstr, char **output, size_t i)
{
	size_t	nl_i;

	if (flexstr_getline(flexstr, output) < 0)
		return (-1);
	if (*output == NULL)
		return (1);
	nl_i = (*flexstr)->nl_i;
	(*flexstr)->nl_flag = 0;
	while (i < (*flexstr)->size)
	{
		if (i + nl_i < (*flexstr)->size)
		{
			(*flexstr)->str[i] = (*flexstr)->str[nl_i + i];
			if ((*flexstr)->nl_flag == 0 && (*flexstr)->str[i] == '\n')
			{
				(*flexstr)->nl_i = i + 1;
				(*flexstr)->nl_flag = 1;
			}
		}
		else
			(*flexstr)->str[i] = 0;
		i++;
	}
	(*flexstr)->cursor -= nl_i;
	return (0);
}
