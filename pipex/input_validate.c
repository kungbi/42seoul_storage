/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_validate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woonshin <woonshin@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 14:35:02 by woonshin          #+#    #+#             */
/*   Updated: 2024/06/06 15:51:06 by woonshin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	input_validate(t_pipex_vars *vars, int n, char *args[], char *envp[])
{
	char	*env_path;
	char	**paths;

	check_infile(vars, args[0]);
	check_outfile(vars, args[n - 1], vars->heredoc);
	init_commands(vars, n - 2, args + 1);
	get_env_path(envp, &env_path);
	paths = ft_split(env_path, ':');
	free(env_path);
	check_commands(vars, paths);
	free_2d_array(paths);
}

void	check_infile(t_pipex_vars *vars, char *filename)
{
	vars->infile.name = filename;
	vars->infile.fd = open(filename, O_RDONLY);
	if (vars->infile.fd < 0)
		return_error("No such file or directory", 1);
}

void	check_outfile(t_pipex_vars *vars, char *filename, int heredoc)
{
	vars->outfile.name = filename;
	if (heredoc == 1)
		vars->outfile.fd = open(filename, O_WRONLY | O_APPEND | O_CREAT, 0644);
	else
		vars->outfile.fd = open(filename, O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (vars->outfile.fd < 0)
		return_error("No such file or directory", 1);
}

void	get_env_path(char *envp[], char **env_path)
{
	size_t	i;

	i = 0;
	while (envp[i] != NULL)
	{
		if (ft_strncmp(envp[i], "PATH=", 5) == 0)
		{
			*env_path = ft_substr(envp[i], 5, ft_strlen(envp[i]));
			if (*env_path == NULL)
				return_error(NULL, 1);
			return ;
		}
		i++;
	}
}

void	get_command_path(t_command *command, char **paths)
{
	char	*path_tmp;
	char	*path;
	size_t	i;

	i = 0;
	while (paths[i] != NULL)
	{
		path_tmp = ft_strjoin(paths[i], "/");
		if (path_tmp == NULL)
			return_error(NULL, 1);
		path = ft_strjoin(path_tmp, command->name);
		if (path == NULL)
			return_error(NULL, 1);
		free(path_tmp);
		if (access(path, F_OK) == 0 && access(path, X_OK) == 0)
		{
			command->path = path;
			return ;
		}
		if (access(path, F_OK) == 0 && access(path, X_OK) != 0)
			return_error("Permission denied", 1);
		free(path);
		i++;
	}
	return_error("command not found", 127);
}
