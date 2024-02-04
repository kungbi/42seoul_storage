/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woonshin <woonshin@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 19:25:34 by woonshin          #+#    #+#             */
/*   Updated: 2024/02/04 23:55:59 by woonshin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

#include <stdio.h>

int	return_error(int return_num);

int	main(int argc, char *argv[])
{
	if (input_validate(argc - 1, argv + 1) == 0)
		return (return_error(0));
	return (0);
}

int	return_error(int return_num)
{
	ft_putendl_fd("Error", 1);
	return (return_num);
}
