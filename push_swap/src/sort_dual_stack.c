/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_dual_stack.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woonshin <woonshin@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 14:56:15 by woonshin          #+#    #+#             */
/*   Updated: 2024/02/08 15:41:32 by woonshin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_dual_stack_a(t_dual_stack *dual_stack, int n)
{
	int	i;
	int	j;
	int	pivots[2];
	int	head_num;
	int	ra_cnt;
	int	rb_cnt;
	int pb_cnt;

	if (n == 0)
		return;
	if (n == 2)
	{
		if (dual_stack->a->head->num > dual_stack->a->head->next->num)
			sa(dual_stack);
		return;
	}
	else if (n == 1)
		return ;
	get_two_pivots(dual_stack->a, n, pivots);
	i = 0;
	ra_cnt = 0;
	rb_cnt = 0;
	pb_cnt = 0;
	while (i < n)
	{
		head_num = dual_stack->a->head->num;
		if (head_num > pivots[1])
		{
			ra(dual_stack);
			ra_cnt++;
		}
		else
		{
			pb(dual_stack);
			pb_cnt++;
			if (head_num > pivots[0])
			{
				rb(dual_stack);
				rb_cnt++;
			}
		}
		i++;
	}
	i = 0;
	j = 0;
	while (i < ra_cnt && j < rb_cnt)
	{
		rrr(dual_stack);
		i++;
		j++;
	}
	for(; i < ra_cnt; i++){
		rra(dual_stack);
	}
	for(; j < rb_cnt; j++){
		rrb(dual_stack);
	}
	sort_dual_stack_a(dual_stack, ra_cnt);
	sort_dual_stack_b(dual_stack, rb_cnt);
	sort_dual_stack_b(dual_stack, pb_cnt - rb_cnt);
}

void	sort_dual_stack_b(t_dual_stack *dual_stack, int n)
{
	int	i;
	int	j;
	int	pivots[2];
	int	head_num;
	int	ra_cnt;
	int	rb_cnt;
	int pa_cnt;

	if (n == 0)
		return ;
	if (n == 2)
	{
		if (dual_stack->b->head->num < dual_stack->b->head->next->num)
			sb(dual_stack);
		pa(dual_stack);
		pa(dual_stack);
		return;
	}
	else if (n == 1)
	{
		pa(dual_stack);
		return;
	}
	get_two_pivots(dual_stack->b, n, pivots);
	i = 0;
	ra_cnt = 0;
	rb_cnt = 0;
	pa_cnt = 0;
	while (i < n)
	{
		head_num = dual_stack->b->head->num;
		if (head_num <= pivots[0])
		{
			rb(dual_stack);
			rb_cnt++;
		}
		else
		{
			pa(dual_stack);
			pa_cnt++;
			if (head_num <= pivots[1])
			{
				ra(dual_stack);
				ra_cnt++;
			}
		}
		i++;
	}
	sort_dual_stack_a(dual_stack, pa_cnt - ra_cnt);
	i = 0;
	j = 0;
	while (i < ra_cnt && i < rb_cnt)
	{
		rrr(dual_stack);
		i++;
		j++;
	}
	for(; i < ra_cnt; i++){
		rra(dual_stack);
	}
	for(; j < rb_cnt; j++){
		rrb(dual_stack);
	}
	sort_dual_stack_a(dual_stack, ra_cnt);
	sort_dual_stack_b(dual_stack, rb_cnt);
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
			break;
	}
	return (min);
}
