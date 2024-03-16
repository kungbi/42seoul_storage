/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woonshin <woonshin@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 23:46:09 by woonshin          #+#    #+#             */
/*   Updated: 2024/03/16 20:33:18 by woonshin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

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

void	get_two_pivots(t_stack *stack, int n, int pivots[])
{
	int	*arr;

	arr = (int *)ft_calloc(n, sizeof(int));
	if (arr == NULL)
		return (return_error());
	lst_to_arr(stack, n, arr);
	quick_sort(arr, 0, n - 1, n);
	pivots[0] = arr[(n - 1) / 3];
	pivots[1] = arr[(n - 1) * 2 / 3];
	free(arr);
}

void	lst_to_arr(t_stack *stack, int n, int *arr)
{
	int		i;
	t_node	*node;

	i = 0;
	node = stack->head;
	while (node != NULL)
	{
		*(arr + i) = node->num;
		node = node->next;
		i++;
		if (i == n)
			break ;
	}
}

void	quick_sort(int *arr, int left, int right, int n)
{
	int	l;
	int	r;
	int	pivot;

	l = left;
	r = right;
	pivot = arr[(l + r) / 2];
	while (l <= r)
	{
		while (arr[l] < pivot)
			l++;
		while (pivot < arr[r])
			r--;
		if (l <= r)
			swap(arr, &l, &r);
	}
	if (left < r)
		quick_sort(arr, left, r, n);
	if (l < right)
		quick_sort(arr, l, right, n);
}

void	swap(int *arr, int *l, int *r)
{
	int	tmp;

	tmp = *(arr + *l);
	*(arr + *l) = *(arr + *r);
	*(arr + *r) = tmp;
	*l = *l + 1;
	*r = *r - 1;
}
