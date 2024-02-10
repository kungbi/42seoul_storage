/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_rotate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woonshin <woonshin@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 01:29:05 by woonshin          #+#    #+#             */
/*   Updated: 2024/02/10 12:56:01 by woonshin         ###   ########.fr       */
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

int	ra(t_dual_stack *dual_stack, t_oper_counter *oper_counter)
{
	if (oper_counter != NULL)
		oper_counter->ra_cnt++;
	if (dual_stack->a->size < 2)
		return (0);
	ft_putendl_fd("ra", 1);
	stack_rotate(dual_stack->a);
	return (0);
}

int	rb(t_dual_stack *dual_stack, t_oper_counter *oper_counter)
{
	if (oper_counter != NULL)
		oper_counter->rb_cnt++;
	if (dual_stack->b->size < 2)
		return (0);
	ft_putendl_fd("rb", 1);
	stack_rotate(dual_stack->b);
	return (0);
}

int	rr(t_dual_stack *dual_stack, t_oper_counter *oper_counter)
{
	oper_counter->ra_cnt++;
	oper_counter->rb_cnt++;
	ft_putendl_fd("rr", 1);
	stack_rotate(dual_stack->a);
	stack_rotate(dual_stack->b);
	return (0);
}
