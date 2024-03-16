/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_reverse_rotate_bonus.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woonshin <woonshin@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 01:29:00 by woonshin          #+#    #+#             */
/*   Updated: 2024/03/16 20:33:48 by woonshin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	dual_stack_restore(t_dual_stack *dual_stack, int ra_cnt, int rb_cnt)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < ra_cnt && j < rb_cnt)
	{
		rrr(dual_stack);
		i++;
		j++;
	}
	while (i < ra_cnt)
	{
		if (ra_cnt < 3 && is_sorted(dual_stack, 'a', ra_cnt))
			break ;
		rra(dual_stack);
		i++;
	}
	while (j < rb_cnt)
	{
		rrb(dual_stack);
		j++;
	}
}

int	stack_reverse_rotate(t_stack *stack)
{
	t_node	*node;

	if (stack->size < 2)
		return (-1);
	node = stack->tail;
	node->prev->next = NULL;
	stack->tail = node->prev;
	node->prev = NULL;
	node->next = stack->head;
	stack->head->prev = node;
	stack->head = node;
	return (0);
}

int	rra(t_dual_stack *dual_stack)
{
	ft_putendl_fd("rra", 1);
	stack_reverse_rotate(dual_stack->a);
	return (0);
}

int	rrb(t_dual_stack *dual_stack)
{
	ft_putendl_fd("rrb", 1);
	stack_reverse_rotate(dual_stack->b);
	return (0);
}

int	rrr(t_dual_stack *dual_stack)
{
	ft_putendl_fd("rrr", 1);
	stack_reverse_rotate(dual_stack->a);
	stack_reverse_rotate(dual_stack->b);
	return (0);
}
