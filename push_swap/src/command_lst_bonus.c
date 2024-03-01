/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_lst_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woonshin <woonshin@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 21:42:24 by woonshin          #+#    #+#             */
/*   Updated: 2024/03/01 22:11:28 by woonshin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	new_command(t_command_lst *command_lst,  char *command)
{
	t_command_lst	*new_command;

	if (command_lst->command == NULL)
	{
		command_lst->command = command;
		return ;
	}
	while (command_lst->next != NULL)
		command_lst = command_lst->next;
	new_command = (t_command_lst*)ft_calloc(1, sizeof(t_command_lst));
	if (new_command == NULL)
		return_error();
	new_command->command = command;
	new_command->next = NULL;
	command_lst->next = new_command;
}

void	clear_command_lst(t_command_lst *command_lst)
{
	t_command_lst	*next;
	t_command_lst	*curr;

	next = command_lst;
	while (next != NULL)
	{
		curr = next;
		next = curr->next;
		free(curr->command);
		free(curr);
	}
}
