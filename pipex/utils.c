/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woonshin <woonshin@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 00:01:44 by woonshin          #+#    #+#             */
/*   Updated: 2024/03/03 19:18:28 by woonshin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	close_all(int *fd, int *fd2)
{
	close(fd[0]);
	close(fd[1]);
	close(fd2[0]);
	close(fd2[1]);
}

void	wait_all(size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		printf("waited: %d\n", wait(NULL));
		i++;
	}
	printf("all waited\n");
}

void	return_error(char *str, int code)
{
	if (str != NULL)
	{
		ft_putstr_fd("pipex: ", 1);
		ft_putstr_fd(str, 1);
		ft_putchar_fd('\n', 1);
		exit(1);
	}
	perror("pipex");
	exit(code);
}
