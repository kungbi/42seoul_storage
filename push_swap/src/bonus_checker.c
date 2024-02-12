/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_checker.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woonshin <woonshin@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 15:50:11 by woonshin          #+#    #+#             */
/*   Updated: 2024/02/11 16:43:35 by woonshin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

#include <stdio.h>
int	main(int argc, char *argv[])
{
	t_dual_stack	*dual_stack;
	char			*command;

	if (input_validate(argc - 1, argv + 1) != 0)
		return_error();
	if (new_dual_stack(&dual_stack) != 0)
		return_error();
	if (dual_stack_init(dual_stack, argc - 1, argv + 1) != 0)
		return_error();
	command = get_next_line(0);
	while (command != NULL)
	{
		if (5 <= ft_strlen(command))
			return_error();
		command_execute(dual_stack, command);
		command = get_next_line(0);
		free(command);
	}
	if (check_stack(dual_stack) == 0)
		ft_putendl_fd("OK", 1);
	else
		ft_putendl_fd("KO", 1);
	return (0);
}

void	return_error(void)
{
	ft_putendl_fd("Error", 1);
	exit(1);
}

int	check_stack(t_dual_stack *dual_stack)
{
	if (dual_stack->b->size != 0)
		return (-1);
	if (is_sorted(dual_stack, 'a', dual_stack->a->size) != 1)
		return (-1);
	return (0);
}

int	command_execute(t_dual_stack *dual_stack, char *command)
{
	if (3 < ft_strlen(command))
		return (command_execute_len3(dual_stack, command));
	if (ft_strncmp(command, "sa", 2) == 0)
		stack_swap(dual_stack->a);
	else if (ft_strncmp(command, "sb", 2) == 0)
		stack_swap(dual_stack->b);
	else if (ft_strncmp(command, "ss", 2) == 0)
	{
		stack_swap(dual_stack->a);
		stack_swap(dual_stack->b);
	}
	else if (ft_strncmp(command, "pa", 2) == 0)
		stack_pop(dual_stack->b, dual_stack->a);
	else if (ft_strncmp(command, "pb", 2) == 0)
		stack_pop(dual_stack->a, dual_stack->b);
	else if (ft_strncmp(command, "ra", 2) == 0)
		stack_rotate(dual_stack->a);
	else if (ft_strncmp(command, "rb", 2) == 0)
		stack_rotate(dual_stack->b);
	else if (ft_strncmp(command, "rr", 2) == 0)
	{
		stack_rotate(dual_stack->a);
		stack_rotate(dual_stack->b);
	}
	return (0);
}

int	command_execute_len3(t_dual_stack *dual_stack, char *command)
{
	int	result;

	if (ft_strncmp(command, "rrr", 3) == 0)
	{
		stack_reverse_rotate(dual_stack->a);
		stack_reverse_rotate(dual_stack->b);
	}
	else if (ft_strncmp(command, "rra", 3) == 0)
		stack_reverse_rotate(dual_stack->a);
	else if (ft_strncmp(command, "rrb", 3) == 0)
		stack_reverse_rotate(dual_stack->b);
	return (result);
}
