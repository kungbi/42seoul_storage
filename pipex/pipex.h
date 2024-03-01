/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woonshin <woonshin@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 13:28:23 by woonshin          #+#    #+#             */
/*   Updated: 2024/03/01 23:02:35 by woonshin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# include "libft.h"
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
}	t_pipex_vars;

void	return_error(char *str);
void	input_validate(t_pipex_vars *vars, int n, char *args[], char *envp[]);
void	pipex_start(t_pipex_vars *vars, int bonus);

void	input_validate(t_pipex_vars *vars, int n, char *args[], char *envp[]);
void	check_outfile(t_file *outfile, char *filename);
void	check_infile(t_file *file, char *filename);
void	get_env_path(char *envp[], char **env_path);
void	get_command_path(t_command *command, char **paths);
void	check_commands(t_pipex_vars *vars, char **paths);
void	init_commands(t_pipex_vars *vars, int n, char **command_name);

#endif