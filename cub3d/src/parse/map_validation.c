/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woonshin <woonshin@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 18:34:40 by woonshin          #+#    #+#             */
/*   Updated: 2024/10/27 23:49:10 by woonshin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"
#include "struct.h"
#include "libft.h"
#include "utils.h"
#include <stdio.h>

int		invalid_character(char **map);
int		player_position(t_system *sys);
int		map_closed(char **map, char **visited, int x, int y);
char	**visited_map(char **map);

int	map_validation(t_system *sys)
{
	char	**visited;
	int		result;

	if (invalid_character(sys->map) == 0)
		return (0);
	if (player_position(sys) == 0)
		return (0);
	visited = visited_map(sys->map);
	result = map_closed(sys->map, visited, (int) sys->player.x,
			(int) sys->player.y);
	arr_2nd_free(visited);
	if (result == 0)
		return (0);
	return (1);
}

int	invalid_character(char **map)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (map[y])
	{
		while (map[y][x])
		{
			if (map[y][x] != ' ' && map[y][x] != '1' && map[y][x] != '0'
				&& map[y][x] != 'W' && map[y][x] != 'E' && map[y][x] != 'N'
				&& map[y][x] != 'S')
				return (0);
			x++;
		}
		x = 0;
		y++;
	}
	return (1);
}

void	set_player_position(t_system *sys, int x, int y)
{
	sys->player.x = (double)x;
	sys->player.y = (double)y;
	sys->player.dir = sys->map[y][x];
	sys->map[y][x] = '0';
}

int	player_position(t_system *sys)
{
	int	x;
	int	y;
	int	found;

	y = 0;
	found = 0;
	while (sys->map[y])
	{
		x = 0;
		while (sys->map[y][x])
		{
			if (sys->map[y][x] == 'N' || sys->map[y][x] == 'S' ||
				sys->map[y][x] == 'W' || sys->map[y][x] == 'E')
			{
				if (found)
					return (0);
				set_player_position(sys, x, y);
				found = 1;
			}
			x++;
		}
		y++;
	}
	return (1);
}

int	map_closed(char **map, char **visited, int x, int y)
{
	if (x < 0 || y < 0 || ft_arrlen(map) <= y || ft_strlen(map[y]) <= (size_t) x
		|| map[y][x] == '\0' || map[y][x] == ' ')
		return (0);
	if (map[y][x] == '1' || visited[y][x] == 1)
		return (1);
	visited[y][x] = 1;
	if (map_closed(map, visited, x + 1, y) == 0)
		return (0);
	if (map_closed(map, visited, x - 1, y) == 0)
		return (0);
	if (map_closed(map, visited, x, y + 1) == 0)
		return (0);
	if (map_closed(map, visited, x, y - 1) == 0)
		return (0);
	return (1);
}
