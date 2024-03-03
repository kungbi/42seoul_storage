/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woonshin <woonshin@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 13:28:23 by woonshin          #+#    #+#             */
/*   Updated: 2024/03/03 14:36:14 by woonshin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# include "libft.h"
# include "gnl.h"
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

typedef struct s_command
{
	char	*name;
	char	*path;
	char	**args;
}	t_command;

typedef struct s_file
{
	int		fd;
	char	*name;
}	t_file;

typedef struct s_pipex_vars
{
	t_file		infile;
	t_file		outfile;
	t_command	*commands;
	size_t		command_cnt;
	int			bonus;
	int			heredoc;
}	t_pipex_vars;

char	**command_split(char const *s);

void	input_validate(t_pipex_vars *vars, int n, char *args[], char *envp[]);
void	check_infile(t_pipex_vars *vars, char *filename);
void	check_outfile(t_pipex_vars *vars, char *filename, int heredoc);
void	get_env_path(char *envp[], char **env_path);
void	get_command_path(t_command *command, char **paths);
void	check_commands(t_pipex_vars *vars, char **paths);
void	init_commands(t_pipex_vars *vars, int n, char **command_name);

void	pipex_start(t_pipex_vars *vars);
void	middle_child(t_pipex_vars *vars, int *fd, int *fd2, size_t i);
void	first_child(t_pipex_vars *vars, int *fd, int *fd2);
void	end_child(t_pipex_vars *vars, int *fd, int *fd2, size_t i);

void	close_all(int *fd, int *fd2);
void	wait_all(size_t n);
void	return_error(char *str, int code);

void	heredoc(t_pipex_vars *vars, char *LIMITER);

#endif