/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_validate_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woonshin <woonshin@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 14:35:02 by woonshin          #+#    #+#             */
/*   Updated: 2024/06/24 14:44:00 by woonshin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	input_validate(t_pipex_vars *vars, int n, char *args[], char *envp[])
{
	(void)envp;
	check_infile(vars, args[0]);
	check_outfile(vars, args[n - 1], vars->heredoc);
	init_commands(vars, n - 2, args + 1);
}

void	check_infile(t_pipex_vars *vars, char *filename)
{
	vars->infile.name = filename;
	vars->infile.fd = open(filename, O_RDONLY);
	if (vars->infile.fd < 0)
	{
		ft_putstr_fd("pipex: ", 2);
		ft_putstr_fd("No such file or directory", 2);
		ft_putchar_fd('\n', 2);
	}
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
	*env_path = ft_calloc(0, 1);
	if (env_path == NULL)
		return_error(NULL, 1);
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
			exit(1);
		free(path);
		i++;
	}
	exit(127);
}
