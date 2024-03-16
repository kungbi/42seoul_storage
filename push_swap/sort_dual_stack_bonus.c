/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_dual_stack_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woonshin <woonshin@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 14:56:15 by woonshin          #+#    #+#             */
/*   Updated: 2024/03/16 20:32:59 by woonshin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	sort_dual_stack_a_core(t_dual_stack *dual_stack,
			t_oper_counter *oper_counter, int pivots[], int n);
void	sort_dual_stack_b_core(t_dual_stack *dual_stack,
			t_oper_counter *oper_counter, int pivots[], int n);

void	sort_dual_stack_a(t_dual_stack *dual_stack, int n)
{
	int				pivots[2];
	t_oper_counter	oper_counter;

	if (is_sorted(dual_stack, 'a', n))
		return ;
	if (n <= 3)
		return (hard_sort_a(dual_stack, n));
	get_two_pivots(dual_stack->a, n, pivots);
	sort_dual_stack_a_core(dual_stack, &oper_counter, pivots, n);
	dual_stack_restore(dual_stack, oper_counter.ra_cnt, oper_counter.rb_cnt);
	sort_dual_stack_a(dual_stack, oper_counter.ra_cnt);
	sort_dual_stack_b(dual_stack, oper_counter.rb_cnt);
	sort_dual_stack_b(dual_stack, oper_counter.pb_cnt - oper_counter.rb_cnt);
}

void	sort_dual_stack_a_core(t_dual_stack *dual_stack,
			t_oper_counter *oper_counter, int pivots[], int n)
{
	int	i;
	int	head_num;

	i = 0;
	init_oper_counter(oper_counter);
	while (i < n)
	{
		head_num = dual_stack->a->head->num;
		if (head_num > pivots[1])
			ra(dual_stack, oper_counter);
		else
		{
			pb(dual_stack, oper_counter);
			if (head_num > pivots[0])
			{
				if (i + 1 < n && dual_stack->a->head
					&& dual_stack->a->head->num > pivots[1] && 0 < ++i)
					rr(dual_stack, oper_counter);
				else
					rb(dual_stack, oper_counter);
			}
		}
		i++;
	}
}

void	sort_dual_stack_b(t_dual_stack *dual_stack, int n)
{
	int				pivots[2];
	t_oper_counter	oper_counter;

	if (is_sorted(dual_stack, 'b', n))
		return (stack_pop_repeat(dual_stack, 'a', n));
	if (n <= 3)
		return (hard_sort_b(dual_stack, n));
	get_two_pivots(dual_stack->b, n, pivots);
	sort_dual_stack_b_core(dual_stack, &oper_counter, pivots, n);
	sort_dual_stack_a(dual_stack, oper_counter.pa_cnt - oper_counter.ra_cnt);
	dual_stack_restore(dual_stack, oper_counter.ra_cnt, oper_counter.rb_cnt);
	sort_dual_stack_a(dual_stack, oper_counter.ra_cnt);
	sort_dual_stack_b(dual_stack, oper_counter.rb_cnt);
}

void	sort_dual_stack_b_core(t_dual_stack *dual_stack,
			t_oper_counter *oper_counter, int pivots[], int n)
{
	int	i;
	int	head_num;

	i = 0;
	init_oper_counter(oper_counter);
	while (i < n)
	{
		head_num = dual_stack->b->head->num;
		if (head_num <= pivots[0])
			rb(dual_stack, oper_counter);
		else
		{
			pa(dual_stack, oper_counter);
			if (head_num <= pivots[1])
			{
				if (i + 1 < n && dual_stack->b->size
					&& dual_stack->b->head->num <= pivots[0] && 0 < ++i)
					rr(dual_stack, oper_counter);
				else
					ra(dual_stack, oper_counter);
			}
		}
		i++;
	}
}

int	sort_dual_stack(t_dual_stack *dual_stack)
{
	sort_dual_stack_a(dual_stack, dual_stack->a->size);
	return (0);
}
