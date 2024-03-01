/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_validate2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woonshin <woonshin@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 22:44:48 by woonshin          #+#    #+#             */
/*   Updated: 2024/03/01 22:45:06 by woonshin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	check_commands(t_pipex_vars *vars, char **paths)
{
	size_t	i;

	i = 0;
	while (i < vars->command_cnt)
	{
		get_command_path(vars->commands + i, paths);
		i++;
	}
}

void	init_commands(t_pipex_vars *vars, int n, char **command_name)
{
	size_t	i;

	vars->command_cnt = n;
	vars->commands = (t_command *)ft_calloc(n, sizeof(t_command));
	if (vars->commands == NULL)
		return_error(NULL);
	i = 0;
	while (i < vars->command_cnt)
	{
		if (command_name[i][0] == '\0')
			return_error("Plz plz plz don't put anything weird in here");
		vars->commands[i].args = ft_split(command_name[i], ' ');
		vars->commands[i].name = vars->commands[i].args[0];
		i++;
	}
}
