/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woonshin <woonshin@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 00:09:17 by woonshin          #+#    #+#             */
/*   Updated: 2024/02/05 08:07:03 by woonshin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
# define STACK_H
# include <stdlib.h>

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

void	print_dual_stack(t_dual_stack *dual_stack);

int	new_dual_stack(t_dual_stack **dual_stack);
int	dual_stack_init(t_dual_stack *dual_stack, int n, char *arr[]);
int	new_stack(t_stack **stack);
int new_node(t_node **node, int num);
int stack_push(t_stack *stack, int num);

int	clean_dual_stack(t_dual_stack **dual_stack);
int clean_stack(t_stack *stack);
int	clean_node(t_node *node);

int sa(t_dual_stack *dual_stack);
int sb(t_dual_stack *dual_stack);
int ss(t_dual_stack *dual_stack);

#endif