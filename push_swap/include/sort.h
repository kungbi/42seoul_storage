/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woonshin <woonshin@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 00:01:42 by woonshin          #+#    #+#             */
/*   Updated: 2024/02/10 15:26:14 by woonshin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SORT_H
# define SORT_H
# include "stack.h"

void	get_two_pivots(t_stack *stack, int n, int pivots[]);
void	lst_to_arr(t_stack *stack, int n, int *arr);
void	quick_sort(int *arr, int left, int right, int n);
void	swap(int *arr, int *l, int *r);

int		get_min(t_stack *stack, int n, int except);

void	init_oper_counter(t_oper_counter *oper_counter);

int		sort_dual_stack(t_dual_stack *dual_stack);

void	sort_dual_stack_a(t_dual_stack *dual_stack, int n);
void	sort_dual_stack_a_core(t_dual_stack *dual_stack,
			t_oper_counter *oper_counter, int pivots[], int n);

void	sort_dual_stack_b(t_dual_stack *dual_stack, int n);
void	sort_dual_stack_b_core(t_dual_stack *dual_stack,
			t_oper_counter *oper_counter, int pivots[], int n);

int		is_sorted(t_dual_stack *dual_stack, char pos, int n);
void	hard_sort_a(t_dual_stack *dual_stack, int n);
void	hard_sort_b(t_dual_stack *dual_stack, int n);

void	hard_sort_three_a(t_dual_stack *dual_stack);
void	hard_sort_three_a_fit(t_dual_stack *dual_stack);
void	hard_sort_three_b(t_dual_stack *dual_stack);
void	hard_sort_three_b_fit(t_dual_stack *dual_stack);

#endif