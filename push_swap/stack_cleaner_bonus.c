/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_cleaner_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woonshin <woonshin@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 00:29:56 by woonshin          #+#    #+#             */
/*   Updated: 2024/03/16 20:33:35 by woonshin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	clean_dual_stack(t_dual_stack **dual_stack)
{
	t_stack	*a_stack;
	t_stack	*b_stack;

	a_stack = (*dual_stack)->a;
	b_stack = (*dual_stack)->b;
	clean_stack(a_stack);
	clean_stack(b_stack);
	free(*dual_stack);
	*dual_stack = NULL;
	return (0);
}

int	clean_stack(t_stack *stack)
{
	t_node	*node;
	t_node	*next_node;

	next_node = stack->head;
	while (next_node != NULL)
	{
		node = next_node;
		next_node = node->next;
		clean_node(node);
	}
	free(stack);
	return (0);
}

int	clean_node(t_node *node)
{
	free(node);
	return (0);
}
