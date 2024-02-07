/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_reverse_rotate.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woonshin <woonshin@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 01:29:00 by woonshin          #+#    #+#             */
/*   Updated: 2024/02/07 23:39:11 by woonshin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
int rra(t_dual_stack *dual_stack);
int rrb(t_dual_stack *dual_stack);
int rrr(t_dual_stack *dual_stack);
*/

int	stack_reverse_rotate(t_stack *stack)
{
	t_node	*node;

	if (stack->size < 2)
		return (-1);
	node = stack->tail;
	node->prev->next = NULL;
	stack->tail = node->prev;
	node->prev = NULL;
	node->next = stack->head;
	stack->head->prev = node;
	stack->head = node;
	return (0);
}

int	rra(t_dual_stack *dual_stack)
{
	ft_putendl_fd("rra", 1);
	stack_reverse_rotate(dual_stack->a);
	return (0);
}

int	rrb(t_dual_stack *dual_stack)
{
	ft_putendl_fd("rrb", 1);
	stack_reverse_rotate(dual_stack->b);
	return (0);
}

int	rrr(t_dual_stack *dual_stack)
{
	ft_putendl_fd("rrr", 1);
	stack_reverse_rotate(dual_stack->a);
	stack_reverse_rotate(dual_stack->b);
	return (0);
}
