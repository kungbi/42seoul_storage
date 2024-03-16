/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woonshin <woonshin@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 00:01:44 by woonshin          #+#    #+#             */
/*   Updated: 2024/03/16 21:17:18 by woonshin         ###   ########.fr       */
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
		// printf("wait reesult %d\n", waitpid(0, &num, 0));
		// printf("num %d\n\n", num);
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
