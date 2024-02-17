/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woonshin <woonshin@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 04:24:19 by woonshin          #+#    #+#             */
/*   Updated: 2024/02/17 10:45:13 by woonshin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int		wall_check(t_map_info *map_info);
void	map_object_detect(t_map_info *map_info);
void	dfs_counter(t_map_info *map_info, 
		t_objects *objects, char **visited, t_pos *curr);

int	map_check(t_map_info *map_info)
{
	t_objects	dfs_result;
	char		**visited;
	t_pos		start;

	map_object_detect(map_info);
	wall_check(map_info);
	dfs_result.collection_cnt = 0;
	dfs_result.exit_cnt = 0;
	start.x = map_info->objects.player.x;
	start.y = map_info->objects.player.y;
	visited = (char **) ft_calloc(map_info->height, sizeof(char *));
	for (int i = 0; i < map_info->height; i++)
		visited[i] = (char *) ft_calloc(map_info->width, sizeof(char));
	dfs_counter(map_info, &dfs_result, visited, &start);
	if (map_info->objects.collection_cnt != dfs_result.collection_cnt ||
		map_info->objects.exit_cnt != dfs_result.exit_cnt)
		return_error();
	return (0);
}

void	dfs_counter(t_map_info *map_info, t_objects *objects, char **visited, t_pos *curr)
{
	int		dxs[4] = {-1, 0, 1, 0};
	int		dys[4] = {0, -1, 0, 1};
	t_pos	next;

	for (int i = 0; i < 4; i++)
	{
		next.x = curr->x + dxs[i];
		next.y = curr->y + dys[i];
		if (!(0 <= next.x && next.x < map_info->width 
			&& 0 <= next.y && next.y < map_info->height))
			continue ;
		if (map_info->map[next.y][next.x] == '1' || visited[next.y][next.x] == 1)
			continue ;
		visited[next.y][next.x] = 1;
		if (map_info->map[next.y][next.x] == 'E')
		{
			objects->exit_cnt++;
			continue ;
		}
		else if (map_info->map[next.y][next.x] == 'C')
		{
			objects->collection_cnt++;
		}
		dfs_counter(map_info, objects, visited, &next);
	}
}

int	wall_check(t_map_info *map_info)
{
	size_t	x;
	size_t	y;

	x = -1;
	y = -1;
	while (++y < map_info->height)
	{
		if (y == 0 || y == map_info->height -1)
		{
			x = -1;
			while (++x < map_info->width)
				if (map_info->map[y][x] != '1')
					return_error();
		}
		else
			if (map_info->map[y][0] != '1' 
				|| map_info->map[y][map_info->width - 1] != '1')
				return_error();
	}
	return (0);
}

void	map_object_detect(t_map_info *map_info)
{
	size_t  x;
	size_t  y;

	y = -1;
	while (++y < map_info->height)
	{
		x = -1;
		while (++x < map_info->width)
		{
			if (map_info->map[y][x] == 'C')
				map_info->objects.collection_cnt++;
			else if (map_info->map[y][x] == 'E')
				map_info->objects.exit_cnt++;
			else if (map_info->map[y][x] == 'P')
			{
				map_info->objects.player_cnt++;
				map_info->objects.player.x = x;
				map_info->objects.player.y = y;
			}
		}
	}
	if (map_info->objects.collection_cnt == 0
		|| map_info->objects.exit_cnt != 1
		|| map_info->objects.exit_cnt != 1
		|| map_info->objects.player_cnt != 1)
		return_error();
}
