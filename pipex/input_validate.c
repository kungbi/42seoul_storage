/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_validate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woonshin <woonshin@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 14:35:02 by woonshin          #+#    #+#             */
/*   Updated: 2024/03/01 21:13:46 by woonshin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	check_infile(t_file *file, char *filename);
void	check_outfile(t_file *outfile, char *filename);
void	init_commands(t_pipex_vars *vars, int n, char **command_name);
void	get_command_path(t_command *command, char **env_paths);
void	check_commands(t_pipex_vars *vars, char **env_paths);
void	get_env_path(char *envp[], char **env_path);

void	input_validate(t_pipex_vars *vars, int n, char *args[], char *envp[])
{
	char	*env_path;
	char	**paths;

	check_infile(&vars->infile, args[0]);
	check_outfile(&vars->outfile, args[3]);
	init_commands(vars, n - 2, args + 1);
	get_env_path(envp, &env_path);
	paths = ft_split(env_path, ':');
	check_commands(vars, paths);
}

void	check_outfile(t_file *outfile, char *filename)
{
	outfile->name = filename;
	outfile->fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (outfile->fd < 0)
		return_error(NULL);
}

void	check_infile(t_file *file, char *filename)
{
	file->name = filename;
	file->fd = open(filename, O_RDONLY);
	if (file->fd < 0)
		return_error(NULL);
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
				return_error(NULL);
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
			return_error(NULL);
		path = ft_strjoin(path_tmp, command->name);
		if (path == NULL)
			return_error(NULL);
		free(path_tmp);
		if (access(path, F_OK) == 0 && access(path, X_OK) == 0)
		{
			command->path = path;
			return ;
		}
		if (access(path, F_OK) == 0 && access(path, X_OK) != 0)
			return_error("Permission denied");
		free(path);
		i++;
	}
	return_error("No such file or directory");
}

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
		vars->commands[i].args = ft_split(command_name[i], ' ');
		vars->commands[i].name = vars->commands[i].args[0];
		i++;
	}
}
