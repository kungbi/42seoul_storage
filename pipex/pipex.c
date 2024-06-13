/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woonshin <woonshin@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 13:28:10 by woonshin          #+#    #+#             */
/*   Updated: 2024/06/13 14:30:16 by woonshin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char *argv[], char *envp[])
{
	t_pipex_vars	vars;
	int				result;

	if (argc != 5)
		return_error("Required 4 arguments", 1);
	vars.bonus = 0;
	vars.heredoc = 0;
	vars.envp = envp;
	input_validate(&vars, argc - 1, argv + 1, envp);
	result = pipex_start(&vars);
	exit(result);
}
