/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_swap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woonshin <woonshin@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 01:29:08 by woonshin          #+#    #+#             */
/*   Updated: 2024/02/09 21:48:23 by woonshin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stack_swap(t_stack *stack)
{
	t_node	*node1;
	t_node	*node2;
	t_node	*tmp;

	if (stack->size < 2)
		return (-1);
	node1 = stack->head;
	node2 = stack->head->next;
	if (stack->tail == node2)
		stack->tail = node1;
	stack->head = node2;

	tmp = node1->prev;
	node1->prev = node2;
	if (node2->next != NULL)
		node2->next->prev = node1;

	tmp = node1->next;
	node1->next = node2->next;
	node2->next = node1;


	stack->head->prev = NULL;
	stack->tail->next = NULL;
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
