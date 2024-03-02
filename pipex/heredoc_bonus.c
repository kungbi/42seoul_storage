/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woonshin <woonshin@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 00:43:44 by woonshin          #+#    #+#             */
/*   Updated: 2024/03/02 09:59:36 by woonshin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	heredoc(t_pipex_vars *vars, char *LIMITER)
{
	int		fd;
	int		limiter_len;
	char	*line;

	vars->heredoc = 1;
	limiter_len = ft_strlen(LIMITER);
	fd = open(".tmp", O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd < 0)
	{
		unlink(".tmp");
		return_error(NULL, 1);
	}
	line = get_next_line(STDIN_FILENO);
	while (line != NULL)
	{
		if (ft_strncmp(line, LIMITER, limiter_len) == 0
			&& line[limiter_len] == '\n')
			break ;
		write(fd, line, ft_strlen(line));
		line = get_next_line(STDIN_FILENO);
	}
	close(fd);
}
