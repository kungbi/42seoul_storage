/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woonshin <woonshin@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 11:00:50 by woonshin          #+#    #+#             */
/*   Updated: 2024/02/10 12:22:32 by woonshin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	hard_sort_three_a(t_dual_stack *dual_stack);
void	hard_sort_three_b(t_dual_stack *dual_stack);

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
		if (pos == 'a' && prev_num > node->num)
			return (0);
		if (pos == 'b' && prev_num < node->num)
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

void	hard_sort_three_a(t_dual_stack *dual_stack)
{
	int	arr[3];

	while (!is_sorted(dual_stack, 'a', 3))
	{
		arr[0] = dual_stack->a->head->num;
		arr[1] = dual_stack->a->head->next->num;
		arr[2] = dual_stack->a->head->next->next->num;
		if ((arr[0] > arr[1] && arr[0] > arr[2])
			|| (arr[2] > arr[0] && arr[2] > arr[1]))
			sa(dual_stack);
		else if ((arr[1] > arr[0] && arr[1] > arr[2]))
		{
			ra(dual_stack, NULL);
			sa(dual_stack);
			rra(dual_stack);
		}
	}
}

void	hard_sort_three_a_fit(t_dual_stack *dual_stack)
{
	int	arr[3];

	while (!is_sorted(dual_stack, 'a', 3))
	{
		arr[0] = dual_stack->a->head->num;
		arr[1] = dual_stack->a->head->next->num;
		arr[2] = dual_stack->a->head->next->next->num;
		if ((arr[0] < arr[1] && arr[1] > arr[2] && arr[0] < arr[2])
			|| (arr[0] > arr[1] && arr[1] < arr[2] && arr[0] < arr[2])
			|| (arr[0] > arr[1] && arr[1] > arr[2] && arr[0] > arr[2]))
		{
			sa(dual_stack);
			continue ;
		}
		if ((arr[0] > arr[1] && arr[1] < arr[2]))
			ra(dual_stack, NULL);
		else
			rra(dual_stack);
	}
}

void	hard_sort_three_b(t_dual_stack *dual_stack)
{
	int	arr[3];

	while (!is_sorted(dual_stack, 'b', 3))
	{
		arr[0] = dual_stack->b->head->num;
		arr[1] = dual_stack->b->head->next->num;
		arr[2] = dual_stack->b->head->next->next->num;
		if ((arr[0] < arr[1] && arr[0] < arr[2])
			|| (arr[2] < arr[0] && arr[2] < arr[1]))
		{
			sb(dual_stack);
		}
		else if ((arr[1] < arr[0] && arr[1] < arr[2]))
		{
			rb(dual_stack, NULL);
			sb(dual_stack);
			rrb(dual_stack);
		}
	}
}

void	hard_sort_three_b_fit(t_dual_stack *dual_stack)
{
	int	arr[3];

	while (!is_sorted(dual_stack, 'b', 3))
	{
		arr[0] = dual_stack->b->head->num;
		arr[1] = dual_stack->b->head->next->num;
		arr[2] = dual_stack->b->head->next->next->num;
		if ((arr[0] > arr[1] && arr[1] < arr[2] && arr[0] > arr[2])
			|| (arr[0] < arr[1] && arr[1] > arr[2] && arr[0] > arr[2])
			|| (arr[0] < arr[1] && arr[1] < arr[2] && arr[0] < arr[2]))
		{
			sb(dual_stack);
			continue ;
		}
		if (arr[0] < arr[1] && arr[1] > arr[2])
			rb(dual_stack, NULL);
		else
			rrb(dual_stack);
	}
}
