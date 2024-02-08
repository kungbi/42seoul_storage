/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woonshin <woonshin@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 00:21:34 by woonshin          #+#    #+#             */
/*   Updated: 2024/02/08 15:22:40 by woonshin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stack_num_push(t_stack *stack, int num)
{
	t_node	*node;
	t_node	*tail;

	stack->size++;
	new_node(&node, num);
	tail = stack->tail;
	if (stack->head == NULL)
	{
		stack->head = node;
		stack->tail = node;
		return (0);
	}
	tail->next = node;
	node->prev = tail;
	stack->tail = node;
	return (0);
}

int	stack_node_push(t_stack *stack, t_node *node)
{
	if (stack->size == 0)
	{
		node->prev = NULL;
		node->next = NULL;
		stack->head = node;
		stack->tail = node;
	}
	else
	{
		stack->head->prev = node;
		node->next = stack->head;
		node->prev = NULL;
		stack->head = node;
	}
	stack->size += 1;
	return (0);
}
