/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_pop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woonshin <woonshin@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 01:29:12 by woonshin          #+#    #+#             */
/*   Updated: 2024/02/10 12:59:09 by woonshin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stack_pop(t_stack *stack_from, t_stack *stack_to)
{
	t_node	*node;

	if (stack_from->size < 1)
		return (-1);
	stack_rotate(stack_from);
	node = stack_from->tail;
	if (stack_from->size == 1)
	{
		stack_from->head = NULL;
		stack_from->tail = NULL;
	}
	else
	{
		stack_from->tail->prev->next = NULL;
		stack_from->tail = stack_from->tail->prev;
	}
	stack_from->size -= 1;
	stack_node_push(stack_to, node);
	return (0);
}

int	pa(t_dual_stack *dual_stack, t_oper_counter *oper_counter)
{
	if (oper_counter != NULL)
		oper_counter->pa_cnt++;
	if (dual_stack->b->size < 1)
		return (0);
	ft_putendl_fd("pa", 1);
	stack_pop(dual_stack->b, dual_stack->a);
	return (0);
}

int	pb(t_dual_stack *dual_stack, t_oper_counter *oper_counter)
{
	if (oper_counter != NULL)
		oper_counter->pb_cnt++;
	if (dual_stack->a->size < 1)
		return (0);
	ft_putendl_fd("pb", 1);
	stack_pop(dual_stack->a, dual_stack->b);
	return (0);
}

void	stack_pop_repeat(t_dual_stack *dual_stack, char pos, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		if (pos == 'a')
			pa(dual_stack, NULL);
		else if (pos == 'b')
			pb(dual_stack, NULL);
		i++;
	}
}
