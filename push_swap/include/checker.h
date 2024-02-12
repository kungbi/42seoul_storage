/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woonshin <woonshin@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 15:50:42 by woonshin          #+#    #+#             */
/*   Updated: 2024/02/11 16:34:06 by woonshin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "stack.h"
# include "get_next_line.h"
# include "sort.h"
# include "libft.h"
# include "push_swap.h"

# include <stdio.h>

int		command_execute(t_dual_stack *dual_stack, char *command);
int		command_execute_len3(t_dual_stack *dual_stack, char *command);
int		check_stack(t_dual_stack *dual_stack);
void	return_error(void);

#endif