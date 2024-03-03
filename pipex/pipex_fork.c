/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_fork.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woonshin <woonshin@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 22:38:15 by woonshin          #+#    #+#             */
/*   Updated: 2024/03/03 20:23:28 by woonshin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	pipex_start(t_pipex_vars *vars)
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
			child_start(vars, fd, i);
		dup2(fd[0], STDIN_FILENO);
		close(fd[0]);
		close(fd[1]);
	}
	wait_all(vars->command_cnt);
}

void	child_start(t_pipex_vars *vars, int *fd, int i)
{
	if (i == 0)
		first_child(vars, fd);
	else if (i == vars->command_cnt - 1)
		end_child(vars, fd);
	else if (vars->bonus == 1)
		middle_child(vars, fd);
	if (execve(vars->commands[i].path, vars->commands[i].args, NULL) < 0)
		return_error(NULL, 1);
}

void	middle_child(t_pipex_vars *vars, int *fd)
{
	dup2(fd[1], STDOUT_FILENO);
	close(fd[1]);
}

void	first_child(t_pipex_vars *vars, int *fd)
{
	close(fd[0]);
	dup2(vars->infile.fd, STDIN_FILENO);
	dup2(fd[1], STDOUT_FILENO);
	close(fd[1]);
	close(vars->infile.fd);
}

void	end_child(t_pipex_vars *vars, int *fd)
{
	close(fd[1]);
	dup2(vars->outfile.fd, STDOUT_FILENO);
	close(vars->outfile.fd);
}
