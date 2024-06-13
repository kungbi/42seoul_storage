/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woonshin <woonshin@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 00:01:44 by woonshin          #+#    #+#             */
/*   Updated: 2024/06/13 14:18:54 by woonshin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	close_all(int *fd, int *fd2)
{
	close(fd[0]);
	close(fd[1]);
	close(fd2[0]);
	close(fd2[1]);
}

int	wait_all(size_t n)
{
	size_t	i;
	int		num;
	int		result;

	i = 0;
	result = 0;
	num = 0;
	while (i < n)
	{
		waitpid(0, &num, 0);
		if (num != 0)
			result = num;
		i++;
	}
	return (result);
}

void	return_error(char *str, int code)
{
	if (str != NULL)
	{
        ft_putstr_fd("pipex: ", 1);
		ft_putstr_fd(str, 1);
		ft_putchar_fd('\n', 1);
		exit(code);
	}
	perror("pipex");
	exit(code);
}

void	free_2d_array(char **arr)
{
	size_t	i;

	i = 0;
	while (arr[i] != NULL)
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}
