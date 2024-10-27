/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woonshin <woonshin@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 20:59:54 by woonshin          #+#    #+#             */
/*   Updated: 2024/10/12 19:28:08 by woonshin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"
#include "error.h"
#include "libft.h"
#include "get_next_line.h"
#include "utils.h"
#include <stdio.h>

int		every_components(t_components *components);
void	parse_components(t_components *components, int fd);
char	**parse_map(int fd);
void	parse_line(t_components *components, char **tokens);

int	parse(t_system *sys, char *filename)
{
	int	fd;

	if (ft_strncmp(filename + ft_strlen(filename) - 4, ".cub", 4))
		error_exit(ARG_ERROR);
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		error_exit(-1);
	parse_components(&sys->components, fd);
	if (!every_components(&sys->components))
		error_exit(PARSE_ERROR);
	sys->map = parse_map(fd);
	if (!map_validation(sys))
		error_exit(PARSE_ERROR);
	close(fd);
	return (0);
}

int	every_components(t_components *components)
{
	int	i;

	if (!components->no || !components->so
		|| !components->we || !components->ea)
		return (0);
	i = 0;
	while (i < 3)
	{
		if (components->f[i] < 0 || components->c[i] < 0)
			return (0);
		i++;
	}
	return (1);
}

void	parse_components(t_components *components, int fd)
{
	char	*line;
	char	**tokens;

	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		tokens = ft_split(line, ' ');
		if (!tokens)
			error_exit(ERROR);
		if (ft_arrlen(tokens) == 2)
			parse_line(components, tokens);
		else if (!(ft_strlen(line) == 1 && line[0] == '\n'))
			error_exit(PARSE_ERROR);
		arr_2nd_free(tokens);
		if (every_components(components))
		{
			if (line)
				free(line);
			break ;
		}
		if (line)
			free(line);
	}
}

char	**parse_map(int fd)
{
	char	*line;
	char	**map;

	map = NULL;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		map = strarr_join(map, newline_trim(line));
	}
	return (map);
}

void	parse_line(t_components *components, char **tokens)
{
	if (ft_arrlen(tokens) == 2 && !ft_strncmp(tokens[0], "NO", 3))
		components->no = newline_trim(ft_strdup(tokens[1]));
	else if (ft_arrlen(tokens) == 2 && !ft_strncmp(tokens[0], "SO", 3))
		components->so = newline_trim(ft_strdup(tokens[1]));
	else if (ft_arrlen(tokens) == 2 && !ft_strncmp(tokens[0], "WE", 3))
		components->we = newline_trim(ft_strdup(tokens[1]));
	else if (ft_arrlen(tokens) == 2 && !ft_strncmp(tokens[0], "EA", 3))
		components->ea = newline_trim(ft_strdup(tokens[1]));
	else if (ft_arrlen(tokens) == 2 && !ft_strncmp(tokens[0], "F", 2))
		arr_map_int(components->f, tokens[1]);
	else if (ft_arrlen(tokens) == 2 && !ft_strncmp(tokens[0], "C", 2))
		arr_map_int(components->c, tokens[1]);
	else
		error_exit(PARSE_ERROR);
}
