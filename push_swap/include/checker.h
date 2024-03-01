/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woonshin <woonshin@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 15:50:42 by woonshin          #+#    #+#             */
/*   Updated: 2024/03/01 22:19:43 by woonshin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "stack.h"
# include "get_next_line.h"
# include "sort.h"
# include "libft.h"
# include "push_swap.h"

typedef struct s_command_lst
{
	struct s_command_lst	*next;
	char					*command;
}	t_command_lst;

int		check_stack(t_dual_stack *dual_stack);
int		command_execute(t_dual_stack *dual_stack, char *command);
void	return_error(void);

void	new_command(t_command_lst *command_lst, char *command);
void	clear_command_lst(t_command_lst *command_lst);

#endif