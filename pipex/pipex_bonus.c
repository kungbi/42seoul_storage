/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woonshin <woonshin@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 23:07:47 by woonshin          #+#    #+#             */
/*   Updated: 2024/03/02 00:02:11 by woonshin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char *argv[], char *envp[])
{
	t_pipex_vars	vars;

	if (argc < 5)
		return_error("Required 4 arguments");
	input_validate(&vars, argc - 1, argv + 1, envp);
	pipex_start(&vars, 1);
	return (0);
}
