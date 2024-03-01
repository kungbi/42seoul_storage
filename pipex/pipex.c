/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woonshin <woonshin@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 13:28:10 by woonshin          #+#    #+#             */
/*   Updated: 2024/03/01 21:12:20 by woonshin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	pipex_start(t_pipex_vars *vars);

int	main(int argc, char *argv[], char *envp[])
{
	t_pipex_vars	vars;

	if (argc != 5)
		return_error("Required 4 arguments");
	input_validate(&vars, argc - 1, argv + 1, envp);
	pipex_start(&vars);
	return (0);
}

void	pipex_start(t_pipex_vars *vars)
{
	int		fd[2];
	int		fd_tmp[2];
	pid_t	pid;
	size_t	i;

	if (pipe(fd) < 0)
		return_error(NULL);
	i = vars->command_cnt;
	while (0 < i)
	{
		pid = fork();
		if (pid < 0)
			return_error(NULL);
		
		if (i == vars->command_cnt && pid == 0)
		{
			close(fd[0]);
			dup2(vars->infile.fd, STDIN_FILENO);
			dup2(fd[1], STDOUT_FILENO);

			if (execve(vars->commands[0].path, vars->commands[0].args, NULL) < 0)
				return_error(NULL);

			close(vars->infile.fd);
			close(fd[1]);
			exit(0);
		}
		else if (i == 1 && pid == 0)
		{
			close(fd[1]);
			dup2(fd[0], STDIN_FILENO);
			dup2(vars->outfile.fd, STDOUT_FILENO);

			if (execve(vars->commands[1].path, vars->commands[1].args, NULL) < 0)
				return_error(NULL);

			close(vars->outfile.fd);
			close(fd[0]);
			exit(0);
		}
	
		i--;
	}
	close(fd[0]);
	close(fd[1]);
	wait(NULL);
	wait(NULL);
}

void	return_error(char *str)
{
	if (str != NULL)
	{
		ft_putstr_fd("pipex: ", 2);
		ft_putstr_fd(str, 2);
		ft_putchar_fd('\n', 2);
		exit(1);
	}
	perror("pipex");
	exit(1);
}
