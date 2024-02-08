/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_swap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woonshin <woonshin@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 01:29:08 by woonshin          #+#    #+#             */
/*   Updated: 2024/02/08 10:27:27 by woonshin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stack_swap(t_stack *stack)
{
	t_node	*node1;
	t_node	*node2;

	if (stack->size < 2)
		return (-1);
	node1 = stack->head;
	node2 = node1->next;
	stack->head = node2;
	if (stack->tail == node2)
		stack->tail = node1;
	node1->prev = node2;
	node1->next = node2->next;
	node2->next = node1;
	node2->prev = NULL;
	return (0);
}

int	sa(t_dual_stack *dual_stack)
{
	ft_putendl_fd("sa", 1);
	stack_swap(dual_stack->a);
	return (0);
}

int	sb(t_dual_stack *dual_stack)
{
	ft_putendl_fd("sb", 1);
	stack_swap(dual_stack->b);
	return (0);
}

int	ss(t_dual_stack *dual_stack)
{
	ft_putendl_fd("ss", 1);
	sa(dual_stack);
	sb(dual_stack);
	return (0);
}
