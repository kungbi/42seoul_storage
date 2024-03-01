/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woonshin <woonshin@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 00:43:44 by woonshin          #+#    #+#             */
/*   Updated: 2024/03/02 01:24:42 by woonshin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	heredoc(t_pipex_vars *vars, char *LIMITER)
{
	int		fd;
	int		LIMITER_LEN;
	char	*line;

	vars->heredoc = 1;
	LIMITER_LEN = ft_strlen(LIMITER);
	fd = open(".tmp", O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd < 0)
	{
		unlink(".tmp");
		return_error(NULL);
	}
	line = get_next_line(STDIN_FILENO);
	while (line != NULL)
	{
		if (ft_strncmp(line, LIMITER, LIMITER_LEN) == 0
			&& line[LIMITER_LEN] == '\n')
			break ;
		write(fd, line, ft_strlen(line));
		line = get_next_line(STDIN_FILENO);
	}
	close(fd);
}
