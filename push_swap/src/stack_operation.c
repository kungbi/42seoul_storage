/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woonshin <woonshin@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 00:21:34 by woonshin          #+#    #+#             */
/*   Updated: 2024/02/05 07:51:36 by woonshin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int stack_push(t_stack *stack, int num)
{
    t_node  *node;
    t_node  *tail;

    stack->size++;
    new_node(&node, num);
    tail = stack->tail;
    if (stack->head == NULL)
    {
        stack->head = node;
        stack->tail = node;
        return (0);
    }
    tail->next = node;
    node->prev = tail;
    stack->tail = node;
    return (0);
}
