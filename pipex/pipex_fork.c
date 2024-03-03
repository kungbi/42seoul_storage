/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_fork.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woonshin <woonshin@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 22:38:15 by woonshin          #+#    #+#             */
/*   Updated: 2024/03/03 19:22:32 by woonshin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	pipex_start(t_pipex_vars *vars)
{
	int		fd[4][2];
	pid_t	pid;
	size_t	i;

	ft_memset(fd, 0, sizeof(fd));
	i = -1;
	while (++i < vars->command_cnt)
	{
		if (i < vars->command_cnt - 1 && i % 2 == 0 && pipe(fd[0]) < 0)
			return_error(NULL, 1);
		if (i < vars->command_cnt - 1 && i % 2 == 1 && pipe(fd[1]) < 0)
			return_error(NULL, 1);
		pid = fork();
		if (pid < 0)
			return_error(NULL, 1);
		if (i == 0 && pid == 0)
			first_child(vars, fd[0], fd[1]);
		else if (i == vars->command_cnt - 1 && pid == 0)
			end_child(vars, fd[0], fd[1], i);
		else if (vars->bonus == 1 && pid == 0)
			middle_child(vars, fd[0], fd[1], i);
	}
	close_all(fd[0], fd[1]);
	while (wait(0) != -1)
		;
	// wait_all(vars->command_cnt);
}

void	middle_child(t_pipex_vars *vars, int *fd, int *fd2, size_t i)
{
	printf("middle_child %d\n", getpid());
	if (i % 2 == 1)
	{
		close(fd[1]);
		close(fd2[0]);
		dup2(fd[0], STDIN_FILENO);
		dup2(fd2[1], STDOUT_FILENO);
	}
	else if (i % 2 == 0)
	{
		close(fd[0]);
		close(fd2[1]);
		dup2(fd2[0], STDIN_FILENO);
		dup2(fd[1], STDOUT_FILENO);
	}
	if (execve(vars->commands[i].path, vars->commands[i].args, NULL) < 0)
		return_error(NULL, 1);
	if (i % 2 == 1)
	{
		close(fd[0]);
		close(fd2[1]);
	}
	else if (i % 2 == 0)
	{
		close(fd[1]);
		close(fd2[0]);
	}
	exit(0);
}

void	first_child(t_pipex_vars *vars, int *fd, int *fd2)
{
	printf("first_child %d\n", getpid());
	close(fd[0]);
	close(fd2[0]);
	close(fd2[1]);
	dup2(vars->infile.fd, STDIN_FILENO);
	dup2(fd[1], STDOUT_FILENO);
	if (execve(vars->commands[0].path, vars->commands[0].args, NULL) < 0)
		return_error(NULL, 1);
	close(vars->infile.fd);
	close(fd[1]);
	exit(0);
}

void	end_child(t_pipex_vars *vars, int *fd, int *fd2, size_t i)
{
	printf("end_child %d\n", getpid());
	close(fd[1]);
	close(fd2[1]);
	if (i % 2 == 0)
		dup2(fd2[0], STDIN_FILENO);
	else
		dup2(fd[0], STDIN_FILENO);
	dup2(vars->outfile.fd, STDOUT_FILENO);
	if (execve(vars->commands[i].path, vars->commands[i].args, NULL) < 0)
		return_error(NULL, 1);
	close(vars->outfile.fd);
	close(fd[0]);
	close(fd2[0]);
	exit(0);
}