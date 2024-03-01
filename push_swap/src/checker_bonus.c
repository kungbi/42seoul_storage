/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woonshin <woonshin@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 15:50:11 by woonshin          #+#    #+#             */
/*   Updated: 2024/03/01 22:15:09 by woonshin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

#include <stdio.h>

void	input_commands(t_command_lst *command_lst);

int	main(int argc, char *argv[])
{
	t_command_lst	command_lst;
	t_command_lst	*command_lst_tmp;
	t_dual_stack	*dual_stack;

	if (argc == 1)
		return (0);
	if (input_validate(argc - 1, argv + 1) != 0)
		return_error();
	if (new_dual_stack(&dual_stack) != 0)
		return_error();
	if (dual_stack_init(dual_stack, argc - 1, argv + 1) != 0)
		return_error();
	input_commands(&command_lst);
	command_lst_tmp = &command_lst;
	while (command_lst_tmp != NULL)
	{
		command_execute(dual_stack, command_lst_tmp->command);
		command_lst_tmp = command_lst_tmp->next;
	}
	check_stack(dual_stack);
	clear_command_lst(&command_lst);
}

void	input_commands(t_command_lst *command_lst)
{
	char	*command;

	command_lst->command = NULL;
	command_lst->next = NULL;

	command = get_next_line(0);
	while (command != NULL)
	{
		new_command(command_lst, command);
		command = get_next_line(0);
	}
}

void	return_error(void)
{
	ft_putendl_fd("Error", 2);
	exit(1);
}

int	check_stack(t_dual_stack *dual_stack)
{
	int	result;

	result = 0;
	if (dual_stack->b->size != 0)
		result = 1;
	if (is_sorted(dual_stack, 'a', dual_stack->a->size) != 1)
		result = 1;
	if (result == 1)
		ft_putendl_fd("KO", 1);
	else if (result == 0)
		ft_putendl_fd("OK", 1);
	exit(0);
}
