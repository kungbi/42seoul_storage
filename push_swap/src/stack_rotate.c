/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_rotate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woonshin <woonshin@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 01:29:05 by woonshin          #+#    #+#             */
/*   Updated: 2024/02/09 21:07:12 by woonshin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stack_rotate(t_stack *stack)
{
	t_node	*node;

	if (stack->size < 2)
		return (-1);
	else if (stack->size == 2)
		return (stack_swap(stack));
	node = stack->head;
	node->next->prev = NULL;
	stack->head = node->next;
	stack->tail->next = node;
	node->prev = stack->tail;
	stack->tail = node;
	node->next = NULL;
	return (0);
}

int	ra(t_dual_stack *dual_stack)
{
	ft_putendl_fd("ra", 1);
	stack_rotate(dual_stack->a);
	return (0);
}

int	rb(t_dual_stack *dual_stack)
{
	ft_putendl_fd("rb", 1);
	stack_rotate(dual_stack->b);
	return (0);
}

int	rr(t_dual_stack *dual_stack)
{
	ft_putendl_fd("rr", 1);
	stack_rotate(dual_stack->a);
	stack_rotate(dual_stack->b);
	return (0);
}
