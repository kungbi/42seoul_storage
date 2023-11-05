/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woonshin <woonshin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 21:45:09 by woonshin          #+#    #+#             */
/*   Updated: 2023/11/06 01:09:59 by woonshin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include <stdio.h>

char	*get_next_line(int fd)
{
	static t_flexlst	*flexlst;
	t_flexlst			*lst;
	char				*result;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	lst = flexlst_push(&flexlst, fd);
	if (lst == NULL)
		return (NULL);
	if (flexlst_getline(lst, &result) < 0)
		return (flexlst_clear(&flexlst, fd));
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

t_flexlst	*flexlst_push(t_flexlst **flexlst, int fd)
{
	t_flexlst	*new_flexlst;
	t_flexlst	*node;

	node = *flexlst;
	while (node != NULL)
	{
		if (node->fd == fd)
			return (node);
		if (node->next == NULL)
			break ;
		node = node->next;
	}
	new_flexlst = (t_flexlst *)malloc(sizeof(t_flexlst) * 1);
	if (new_flexlst == NULL)
		return (NULL);
	if (flexstr_new(&new_flexlst->flexstr, BUFFER_SIZE) != 0)
	{
		free(new_flexlst);
		return (NULL);
	}
	new_flexlst->fd = fd;
	new_flexlst->next = NULL;
	if (*flexlst == NULL)
		*flexlst = new_flexlst;
	else
		node->next = new_flexlst;
	return (new_flexlst);
}

int	flexlst_getline(t_flexlst *flexlst, char **output)
{
	char		buffer[BUFFER_SIZE];
	long		n;

	if (flexstr_linepop(&(flexlst)->flexstr, output, 0) < 0)
		return (-1);
	if (*output != NULL)
		return (0);
	while (1)
	{
		n = read((flexlst)->fd, buffer, BUFFER_SIZE);
		if (n == 0)
			break ;
		if (n < 0)
			return (-1);
		if (flexstr_append(&(flexlst)->flexstr, buffer, n) != 0
			|| flexstr_linepop(&(flexlst)->flexstr, output, 0) < 0)
			return (-1);
		if (*output != NULL)
			return (0);
	}
	if (0 <= n && 0 < (flexlst)->flexstr->cursor)
	{
		(flexlst)->flexstr->nl_flag = 1;
		(flexlst)->flexstr->nl_i = (flexlst)->flexstr->cursor;
	}
	flexstr_linepop(&(flexlst)->flexstr, output, 0);
	flexstr_free(&(flexlst)->flexstr, -1);
	if (*output != NULL)
		return (0);
	return (-1);
}

char	*flexlst_clear(t_flexlst **flexlst, int fd)
{
	t_flexlst	*curr_node;
	t_flexlst	*tmp;

	if (flexlst == NULL)
		return (NULL);
	curr_node = *flexlst;
	if (curr_node->fd == fd)
	{
		*flexlst = curr_node->next;
		flexstr_free(&curr_node->flexstr, -1);
		free(curr_node);
		return (NULL);
	}
	while (curr_node != NULL)
	{
		if (curr_node->next->fd == fd)
		{
			tmp = curr_node->next;
			curr_node->next = tmp->next;
			flexstr_free(&tmp->flexstr, -1);
			free(tmp);
			return (NULL);
		}
		curr_node = curr_node->next;
	}
	return (NULL);
}

