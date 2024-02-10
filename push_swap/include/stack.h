/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woonshin <woonshin@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 00:09:17 by woonshin          #+#    #+#             */
/*   Updated: 2024/02/10 12:18:59 by woonshin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
# define STACK_H
# include "sort.h"
# include <stdlib.h>

typedef struct s_operation_counter
{
	int	ra_cnt;
	int	rb_cnt;
	int	pa_cnt;
	int	pb_cnt;
}	t_oper_counter;

typedef struct s_dual_stack
{
	struct s_stack	*a;
	struct s_stack	*b;
}	t_dual_stack;

typedef struct s_stack
{
	struct s_node	*head;
	struct s_node	*tail;
	size_t			size;
}	t_stack;

typedef struct s_node
{
	int				num;
	struct s_node	*next;
	struct s_node	*prev;
}	t_node;

int		dual_stack_init(t_dual_stack *dual_stack, int n, char *arr[]);

int		new_dual_stack(t_dual_stack **dual_stack);
int		new_stack(t_stack **stack);
int		new_node(t_node **node, int num);

int		stack_num_push(t_stack *stack, int num);
int		stack_node_push(t_stack *stack, t_node *node);

int		clean_dual_stack(t_dual_stack **dual_stack);
int		clean_stack(t_stack *stack);
int		clean_node(t_node *node);

int		stack_swap(t_stack *stack);
int		sa(t_dual_stack *dual_stack);
int		sb(t_dual_stack *dual_stack);
int		ss(t_dual_stack *dual_stack);

void	dual_stack_restore(t_dual_stack *dual_stack, int i, int j);
int		stack_rotate(t_stack *stack);
int		ra(t_dual_stack *dual_stack, t_oper_counter *oper_counter);
int		rb(t_dual_stack *dual_stack, t_oper_counter *oper_counter);
int		rr(t_dual_stack *dual_stack, t_oper_counter *oper_counter);

int		stack_reverse_rotate(t_stack *stack);
int		rra(t_dual_stack *dual_stack);
int		rrb(t_dual_stack *dual_stack);
int		rrr(t_dual_stack *dual_stack);

int		stack_pop(t_stack *stack_from, t_stack *stack_to);
void	stack_pop_repeat(t_dual_stack *dual_stack, char pos, int n);
int		pa(t_dual_stack *dual_stack, t_oper_counter *oper_counter);
int		pb(t_dual_stack *dual_stack, t_oper_counter *oper_counter);

void	print_stack(t_stack *stack);

#endif