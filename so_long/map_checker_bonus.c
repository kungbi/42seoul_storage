/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woonshin <woonshin@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 04:24:19 by woonshin          #+#    #+#             */
/*   Updated: 2024/03/11 14:43:21 by woonshin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int		wall_check(t_map_info *map_info);
void	map_object_detect(t_map_info *map_info);
void	dfs_counter(t_map_info *map_info, t_objects *objects,
			char **visited, t_pos *curr);
void	dxdy_init(int *dxs, int *dys);

int	map_check(t_map_info *map_info)
{
	t_objects	dfs_result;
	char		**visited;
	t_pos		start;

	map_object_detect(map_info);
	if (map_info->objects.collection_cnt == 0
		|| map_info->objects.exit_cnt != 1
		|| map_info->objects.player_cnt != 1)
		return_error();
	wall_check(map_info);
	dfs_result.collection_cnt = 0;
	dfs_result.exit_cnt = 0;
	start.x = map_info->objects.player.x;
	start.y = map_info->objects.player.y;
	new_2d_array(&visited, map_info->width, map_info->height);
	dfs_counter(map_info, &dfs_result, visited, &start);
	free_2d_array(visited, map_info->height);
	if (map_info->objects.collection_cnt != dfs_result.collection_cnt
		|| map_info->objects.exit_cnt != dfs_result.exit_cnt)
		return_error();
	return (0);
}

void	dxdy_init(int *dxs, int *dys)
{
	dxs[0] = -1;
	dxs[1] = 0;
	dxs[2] = 1;
	dxs[3] = 0;
	dys[0] = 0;
	dys[1] = -1;
	dys[2] = 0;
	dys[3] = 1;
}

void	dfs_counter(t_map_info *map_info, t_objects *objects,
			char **visited, t_pos *curr)
{
	int		dxs[4];
	int		dys[4];
	t_pos	next;
	size_t	i;

	if (map_info->map[curr->y][curr->x] == 'E')
		return ;
	dxdy_init(dxs, dys);
	i = -1;
	while (++i < 4)
	{
		next.x = curr->x + dxs[i];
		next.y = curr->y + dys[i];
		if (!is_frame(map_info, next.x, next.y))
			continue ;
		if (map_info->map[next.y][next.x] == '1'
			|| visited[next.y][next.x] == 1)
			continue ;
		visited[next.y][next.x] = 1;
		if (map_info->map[next.y][next.x] == 'E')
			objects->exit_cnt++;
		if (map_info->map[next.y][next.x] == 'C')
			objects->collection_cnt++;
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
	size_t		x;
	size_t		y;

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
			else if (map_info->map[y][x] != '0'
				&& map_info->map[y][x] != '1')
				return_error();
		}
	}
}
