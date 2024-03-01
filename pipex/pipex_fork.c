/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_fork.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woonshin <woonshin@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 22:38:15 by woonshin          #+#    #+#             */
/*   Updated: 2024/03/02 00:39:12 by woonshin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	first_child(t_pipex_vars *vars, int *fd, int *fd2);
void	end_child(t_pipex_vars *vars, int *fd, int *fd2, size_t i);
void	middle_child(t_pipex_vars *vars, int *fd, int *fd2, size_t i);
void	wait_all(size_t n);
void	close_all(int *fd, int *fd2);

void	pipex_start(t_pipex_vars *vars, int bonus)
{
	int		fd[2][2];
	pid_t	pid;
	size_t	i;

	i = -1;
	while (++i < vars->command_cnt)
	{
		if (i < vars->command_cnt - 1 && i % 2 == 0 && pipe(fd[0]) < 0)
			return_error(NULL);
		if (i < vars->command_cnt - 1 && i % 2 == 1 && pipe(fd[1]) < 0)
			return_error(NULL);
		pid = fork();
		if (pid < 0)
			return_error(NULL);
		if (i == 0 && pid == 0)
			first_child(vars, fd[0], fd[1]);
		else if (i == vars->command_cnt - 1 && pid == 0)
			end_child(vars, fd[0], fd[1], i);
		else if (bonus == 1 && pid == 0)
			middle_child(vars, fd[0], fd[1], i);
	}
	close_all(fd[0], fd[1]);
	wait_all(vars->command_cnt);
}

void	middle_child(t_pipex_vars *vars, int *fd, int *fd2, size_t i)
{
	if (i % 2 == 1)
	{
		dup2(fd[0], STDIN_FILENO);
		dup2(fd2[1], STDOUT_FILENO);
		close(fd[1]);
		close(fd2[0]);
	}
	else if (i % 2 == 0)
	{
		dup2(fd2[0], STDIN_FILENO);
		dup2(fd[1], STDOUT_FILENO);
		close(fd2[1]);
		close(fd[0]);
	}
	if (execve(vars->commands[i].path, vars->commands[i].args, NULL) < 0)
		return_error(NULL);
	close(fd2[1]);
	close(fd[1]);
}

void	first_child(t_pipex_vars *vars, int *fd, int *fd2)
{
	close(fd[0]);
	dup2(vars->infile.fd, STDIN_FILENO);
	dup2(fd[1], STDOUT_FILENO);
	if (execve(vars->commands[0].path, vars->commands[0].args, NULL) < 0)
		return_error(NULL);
	close(vars->infile.fd);
	close(fd[1]);
	close(fd2[0]);
	close(fd2[1]);
	exit(0);
}

void	end_child(t_pipex_vars *vars, int *fd, int *fd2, size_t i)
{
	close(fd[1]);
	close(fd2[1]);
	if (i % 2 == 0)
		dup2(fd2[0], STDIN_FILENO);
	else
		dup2(fd[0], STDIN_FILENO);
	dup2(vars->outfile.fd, STDOUT_FILENO);
	if (execve(vars->commands[i].path, vars->commands[i].args, NULL) < 0)
		return_error(NULL);
	close(vars->outfile.fd);
	close(fd[0]);
	close(fd2[0]);
	exit(0);
}
