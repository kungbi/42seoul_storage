/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woonshin <woonshin@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 21:00:15 by woonshin          #+#    #+#             */
/*   Updated: 2024/02/05 01:12:05 by woonshin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
1. stack 생성하는 함수 (두 개짜리 a, b)
2. stack(a)에 추가하는 push 함수
3. 각종 연산 구현
4. dual_stack을 지우는 함수
*/

int	new_dual_stack(t_dual_stack **dual_stack)
{
	t_stack	*a_stack;
	t_stack	*b_stack;

	*dual_stack = (t_dual_stack*)malloc(sizeof(t_dual_stack) * 1);
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
	*stack = (t_stack*)malloc(sizeof(t_stack) * 1);
	if (stack == NULL)
		return_error();
	(*stack)->head = NULL;
	(*stack)->tail = NULL;
	(*stack)->size = 0;
	return (0);
}

int new_node(t_node **node, int num)
{
	*node = (t_node*)malloc(sizeof(t_node) * 1);
	if ((*node) == NULL)
		return_error();
	(*node)->next = NULL;
	(*node)->prev = NULL;
	(*node)->num = num;
	return (0);
}

int	dual_stack_init(t_dual_stack *dual_stack, int n, char *arr[])
{
	int	i;
	t_stack *a_stack;

	a_stack = dual_stack->a;
	i = 0;
	while (i < n)
	{
		stack_push(a_stack, ft_atoi(arr[i]));
		i++;
	}
	return (0);
}
