/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_dual_stack.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woonshin <woonshin@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 14:56:15 by woonshin          #+#    #+#             */
/*   Updated: 2024/02/09 18:33:58 by woonshin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_dual_stack_a(t_dual_stack *dual_stack, int n)
{
	int				i;
	int				j;
	int				pivots[2];
	int				head_num;
	t_oper_counter	oper_counter;

	if (n <= 3)
		return hard_sort_a(dual_stack, n);
	get_two_pivots(dual_stack->a, n, pivots);
	if (is_sorted(dual_stack, 'a', n))
		return ;
	i = 0;
	oper_counter.ra_cnt = 0;
	oper_counter.rb_cnt = 0;
	oper_counter.pb_cnt = 0;
	while (i < n)
	{
		head_num = dual_stack->a->head->num;
		if (head_num > pivots[1])
		{
			ra(dual_stack);
			oper_counter.ra_cnt++;
		}
		else
		{
			pb(dual_stack);
			oper_counter.pb_cnt++;
			if (head_num > pivots[0])
			{
				rb(dual_stack);
				oper_counter.rb_cnt++;
			}
		}
		i++;
	}
	dual_stack_restore(dual_stack, oper_counter.ra_cnt, oper_counter.rb_cnt);
	sort_dual_stack_a(dual_stack, oper_counter.ra_cnt);
	sort_dual_stack_b(dual_stack, oper_counter.rb_cnt);
	sort_dual_stack_b(dual_stack, oper_counter.pb_cnt - oper_counter.rb_cnt);
}

void	sort_dual_stack_b(t_dual_stack *dual_stack, int n)
{
	int				i;
	int				j;
	int				pivots[2];
	int				head_num;
	t_oper_counter	oper_counter;

	if (n <= 3)
		return hard_sort_b(dual_stack, n);
	get_two_pivots(dual_stack->b, n, pivots);
	i = 0;
	oper_counter.ra_cnt = 0;
	oper_counter.rb_cnt = 0;
	oper_counter.pa_cnt = 0;
	while (i < n)
	{
		head_num = dual_stack->b->head->num;
		if (head_num < pivots[0])
		{
			rb(dual_stack);
			oper_counter.rb_cnt++;
		}
		else
		{
			pa(dual_stack);
			oper_counter.pa_cnt++;
			if (head_num < pivots[1])
			{
				ra(dual_stack);
				oper_counter.ra_cnt++;
			}
		}
		i++;
	}
	sort_dual_stack_a(dual_stack, oper_counter.pa_cnt - oper_counter.ra_cnt);
	dual_stack_restore(dual_stack, oper_counter.ra_cnt, oper_counter.rb_cnt);
	sort_dual_stack_a(dual_stack, oper_counter.ra_cnt);
	sort_dual_stack_b(dual_stack, oper_counter.rb_cnt);
}

int	sort_dual_stack(t_dual_stack *dual_stack)
{
	sort_dual_stack_a(dual_stack, dual_stack->a->size);
	return (0);
}

int	get_min(t_stack *stack, int n, int except)
{
	int		min;
	int		i;
	t_node	*node;

	node = stack->head;
	i = 0;
	while (node != NULL)
	{
		if (min > node->num && node->num != except)
			min = node->num;
		node = node->next;
		i++;
		if (i == n)
			break ;
	}
	return (min);
}
