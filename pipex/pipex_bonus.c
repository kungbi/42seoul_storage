/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woonshin <woonshin@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 23:07:47 by woonshin          #+#    #+#             */
/*   Updated: 2024/03/02 10:00:26 by woonshin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char *argv[], char *envp[])
{
	t_pipex_vars	vars;
	int				i;

	if (argc < 5)
		return_error("Required 4 arguments", 1);
	if (ft_strncmp(argv[1], "heredoc", 8) == 0)
	{
		if (argc < 6)
			return_error("Required 4 arguments", 1);
		ft_strlcpy(argv[1], ".tmp", 8);
		heredoc(&vars, argv[2]);
		i = 1;
		while (++i < argc - 1)
			argv[i] = argv[i + 1];
		argc--;
	}
	input_validate(&vars, argc - 1, argv + 1, envp);
	vars.bonus = 1;
	pipex_start(&vars);
	if (vars.heredoc == 1)
		unlink(".tmp");
	return (0);
}
