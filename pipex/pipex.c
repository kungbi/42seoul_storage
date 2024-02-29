/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woonshin <woonshin@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 13:28:10 by woonshin          #+#    #+#             */
/*   Updated: 2024/02/29 18:50:21 by woonshin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char *argv[], char *envp[])
{
	t_pipex_vars	vars;
	int				pipe[2];

	if (argc != 5)
		return_error("Required 4 arguments");


	input_validate(&vars, argc - 1, argv + 1, envp);
	


	// 2. output 생성

	// 3. 프로세스 생성 (명령어 두 개)
	// 4. 파이프로 infile내용 전달 
	return (0);
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
