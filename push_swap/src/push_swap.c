/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woonshin <woonshin@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 19:25:34 by woonshin          #+#    #+#             */
/*   Updated: 2024/02/10 15:54:40 by woonshin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_dual_stack	*dual_stack;

	if (input_validate(argc - 1, argv + 1) != 0)
		return_error();
	new_dual_stack(&dual_stack);
	dual_stack_init(dual_stack, argc - 1, argv + 1);
	if (!is_sorted(dual_stack, 'a', dual_stack->a->size))
		sort_dual_stack(dual_stack);
	clean_dual_stack(&dual_stack);
	return (0);
}

void	return_error(void)
{
	ft_putendl_fd("Error", 1);
	exit(1);
}
