/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woonshin <woonshin@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 21:45:09 by woonshin          #+#    #+#             */
/*   Updated: 2024/10/12 15:29:44 by woonshin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static t_flexlst	*flexlst;
	t_flexlst			*lst;
	char				*result;
	int					getline_result;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	lst = flexlst_push(&flexlst, fd);
	if (lst == NULL)
		return (NULL);
	getline_result = flexlst_getline(lst, &result);
	if (getline_result < 0)
		return (flexlst_clear(&flexlst, fd));
	if (getline_result == 0)
		return (result);
	if (0 < (lst)->flexstr->cursor)
	{
		(lst)->flexstr->nl_flag = 1;
		(lst)->flexstr->nl_i = (lst)->flexstr->cursor;
	}
	flexstr_linepop(&(lst)->flexstr, &result, 0);
	flexstr_free(&(lst)->flexstr, -1);
	flexlst_clear(&flexlst, fd);
	return (result);
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
	while (node != NULL && (node->next != NULL || node->fd == fd))
	{
		if (node->fd == fd)
			return (node);
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
	return (1);
}

char	*flexlst_clear(t_flexlst **flexlst, int fd)
{
	t_flexlst	*curr_node;
	t_flexlst	*tmp;

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
