/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woonshin <woonshin@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 21:00:15 by woonshin          #+#    #+#             */
/*   Updated: 2024/02/08 15:23:32 by woonshin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// 임시 함수
void	print_dual_stack(t_dual_stack *dual_stack)
{
	t_node	*node;

	printf("<a>\n");
	node = dual_stack->a->head;
	while (node)
	{
		printf("%d -> ", node->num);
		node = node->next;
	}
	printf("\n");
	node = dual_stack->a->tail;
	while (node)
	{
		printf("%d -> ", node->num);
		node = node->prev;
	}
	printf("\n<b>\n");
	node = dual_stack->b->head;
	while (node)
	{
		printf("%d -> ", node->num);
		node = node->next;
	}
	printf("\n");
	node = dual_stack->b->tail;
	while (node)
	{
		printf("%d -> ", node->num);
		node = node->prev;
	}
	printf("\n");
}

int	new_dual_stack(t_dual_stack **dual_stack)
{
	t_stack	*a_stack;
	t_stack	*b_stack;

	*dual_stack = (t_dual_stack *)ft_calloc(1, sizeof(t_dual_stack));
	if (*dual_stack == NULL)
		return_error();
	new_stack(&a_stack);
	new_stack(&b_stack);
	(*dual_stack)->a = a_stack;
	(*dual_stack)->b = b_stack;
	return (0);
}

int	new_stack(t_stack **stack)
{
	*stack = (t_stack *)ft_calloc(1, sizeof(t_stack));
	if (stack == NULL)
		return_error();
	(*stack)->head = NULL;
	(*stack)->tail = NULL;
	(*stack)->size = 0;
	return (0);
}

int	new_node(t_node **node, int num)
{
	*node = (t_node *)ft_calloc(1, sizeof(t_node));
	if ((*node) == NULL)
		return_error();
	(*node)->next = NULL;
	(*node)->prev = NULL;
	(*node)->num = num;
	return (0);
}

int	dual_stack_init(t_dual_stack *dual_stack, int n, char *arr[])
{
	int		i;
	t_stack	*a_stack;

	a_stack = dual_stack->a;
	i = 0;
	while (i < n)
	{
		stack_num_push(a_stack, ft_atoi(arr[i]));
		i++;
	}
	return (0);
}
