/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woonshin <woonshin@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 19:25:34 by woonshin          #+#    #+#             */
/*   Updated: 2024/03/16 20:32:48 by woonshin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

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
	ft_putendl_fd("Error", 2);
	exit(1);
}
