/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woonshin <woonshin@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 19:25:34 by woonshin          #+#    #+#             */
/*   Updated: 2024/02/05 01:20:25 by woonshin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


void leak() {
    system("leaks push_swap");
}

int	main(int argc, char *argv[])
{
	t_dual_stack	*dual_stack;

	// atexit(leak);
	if (input_validate(argc - 1, argv + 1) == 0)
		return_error();
	dual_stack = NULL;
	new_dual_stack(&dual_stack);
	dual_stack_init(dual_stack, argc - 1, argv + 1);
	// 정렬 하기.
	// opcount = sort(dual_stack);
	clean_dual_stack(&dual_stack);
	return (0);
}

void	return_error()
{
	ft_putendl_fd("Error", 1);
	exit(0);
}
