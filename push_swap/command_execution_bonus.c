/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_execution_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woonshin <woonshin@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 20:50:23 by woonshin          #+#    #+#             */
/*   Updated: 2024/03/16 20:35:19 by woonshin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

int		command_validate(char *command);
void	command_execute_len2(t_dual_stack *dual_stack, char *command);
void	command_execute_len3(t_dual_stack *dual_stack, char *command);

int	command_execute(t_dual_stack *dual_stack, char *command)
{
	int	len;

	len = ft_strlen(command);
	if (len < 2)
		return_error();
	if (command[len - 1] != '\n')
		return_error();
	command[len - 1] = '\0';
	len--;
	command_validate(command);
	if (len == 3)
		command_execute_len3(dual_stack, command);
	else if (len == 2)
		command_execute_len2(dual_stack, command);
	return (0);
}

int	command_validate(char *command)
{
	int	i;
	int	n;

	n = ft_strlen(command);
	if (n != 2 && n != 3)
		return_error();
	i = 0;
	while (i < n)
	{
		if (!(command[i] == 'r' || command[i] == 'p' || command[i] == 's'
				|| command[i] == 'a' || command[i] == 'b'))
			return_error();
		i++;
	}
	return (0);
}

void	command_execute_len2(t_dual_stack *dual_stack, char *command)
{
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
	else
		return_error();
}

void	command_execute_len3(t_dual_stack *dual_stack, char *command)
{
	if (ft_strncmp(command, "rrr", 3) == 0)
	{
		stack_reverse_rotate(dual_stack->a);
		stack_reverse_rotate(dual_stack->b);
	}
	else if (ft_strncmp(command, "rra", 3) == 0)
		stack_reverse_rotate(dual_stack->a);
	else if (ft_strncmp(command, "rrb", 3) == 0)
		stack_reverse_rotate(dual_stack->b);
	else
		return_error();
}
