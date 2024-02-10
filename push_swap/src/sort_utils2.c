/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woonshin <woonshin@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 11:00:50 by woonshin          #+#    #+#             */
/*   Updated: 2024/02/10 15:13:28 by woonshin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_oper_counter(t_oper_counter *oper_counter)
{
	oper_counter->ra_cnt = 0;
	oper_counter->rb_cnt = 0;
	oper_counter->pa_cnt = 0;
	oper_counter->pb_cnt = 0;
}

int	is_sorted(t_dual_stack *dual_stack, char pos, int n)
{
	t_stack	*stack;
	t_node	*node;
	int		prev_num;
	int		i;

	if (pos == 'a')
		stack = dual_stack->a;
	if (pos == 'b')
		stack = dual_stack->b;
	i = 0;
	if (stack->head == NULL)
		return (0);
	prev_num = stack->head->num;
	node = stack->head->next;
	while (node != NULL)
	{
		if ((pos == 'a' && prev_num > node->num)
			|| pos == 'b' && prev_num < node->num)
			return (0);
		prev_num = node->num;
		node = node->next;
		if (n <= ++i)
			return (1);
	}	
	return (1);
}

void	hard_sort_a(t_dual_stack *dual_stack, int n)
{
	if (n == 0)
		return ;
	if (is_sorted(dual_stack, 'a', n) == 1)
		return ;
	if (n == 2)
		sa(dual_stack);
	else if (n == 3)
	{
		if (dual_stack->a->size == 3)
			hard_sort_three_a_fit(dual_stack);
		else
			hard_sort_three_a(dual_stack);
	}
}

void	hard_sort_b(t_dual_stack *dual_stack, int n)
{
	int	i;

	if (n == 0)
		return ;
	if (n == 2)
		sb(dual_stack);
	else if (n == 3)
	{
		if (dual_stack->b->size == 3)
			hard_sort_three_b_fit(dual_stack);
		else
			hard_sort_three_b(dual_stack);
	}
	stack_pop_repeat(dual_stack, 'a', n);
}
