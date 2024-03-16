/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils3_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woonshin <woonshin@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 15:09:02 by woonshin          #+#    #+#             */
/*   Updated: 2024/03/16 20:33:27 by woonshin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

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
