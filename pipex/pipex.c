/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woonshin <woonshin@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 13:28:10 by woonshin          #+#    #+#             */
/*   Updated: 2024/03/02 10:01:23 by woonshin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char *argv[], char *envp[])
{
	t_pipex_vars	vars;

	if (argc != 5)
		return_error("Required 4 arguments", 1);
	input_validate(&vars, argc - 1, argv + 1, envp);
	vars.bonus = 0;
	pipex_start(&vars);
	return (0);
}
