/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_fork.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woonshin <woonshin@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 22:38:15 by woonshin          #+#    #+#             */
/*   Updated: 2024/06/24 14:41:41 by woonshin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	pipex_start(t_pipex_vars *vars)
{
	int		fd[2];
	pid_t	pid;
	size_t	i;

	ft_memset(fd, 0, sizeof(fd));
	i = -1;
	while (++i < vars->command_cnt)
	{
		if (pipe(fd) < 0)
			return_error(NULL, 1);
		pid = fork();
		if (pid < 0)
			return_error(NULL, 1);
		if (pid == 0)
		{
			validation_commands(vars, i);
			child_start(vars, fd, i);
		}
		dup2(fd[0], STDIN_FILENO);
		close(fd[0]);
		close(fd[1]);
	}
	return (wait_all(vars->command_cnt));
}

void	child_start(t_pipex_vars *vars, int *fd, size_t i)
{
	if (i == 0)
		first_child(vars, fd);
	else if (i == vars->command_cnt - 1)
		end_child(vars, fd);
	else if (vars->bonus == 1)
		middle_child(fd);
	if (execve(vars->commands[i].path, vars->commands[i].args, vars->envp) < 0)
		return_error(NULL, 127);
}

void	middle_child(int *fd)
{
	dup2(fd[1], STDOUT_FILENO);
	close(fd[1]);
}

void	first_child(t_pipex_vars *vars, int *fd)
{
	close(fd[0]);
	if (vars->infile.fd < 0)
		exit(0);
	dup2(vars->infile.fd, STDIN_FILENO);
	close(vars->infile.fd);
	dup2(fd[1], STDOUT_FILENO);
	close(fd[1]);
}

void	end_child(t_pipex_vars *vars, int *fd)
{
	close(fd[1]);
	dup2(vars->outfile.fd, STDOUT_FILENO);
	close(vars->outfile.fd);
}
