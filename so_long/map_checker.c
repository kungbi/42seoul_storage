/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woonshin <woonshin@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 04:24:19 by woonshin          #+#    #+#             */
/*   Updated: 2024/02/17 09:27:15 by woonshin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int		wall_check(t_map_info *map_info);
void	map_object_detect(t_map_info *map_info);

int	map_check(t_map_info *map_info)
{
	map_object_detect(map_info);
	wall_check(map_info);

	return (0);
}

int dfs_counter(t_map_info *map_info, t_objects *objects, int **visited, t_pos curr)
{
	int	dxs[4] = {-1, 0, 1, 0};
	int	dys[4] = {0, -1, 0, 1};
	int nx;
	int ny;

	for (int i = 0; i < 4; i++)
	{
		nx = curr.x + dxs[i];
		ny = curr.y + dys[i];
		if (!(0 <= nx < map_info->width && 0 <= ny < map_info->height))
			continue ;
		
	}
}

int	wall_check(t_map_info *map_info)
{
	size_t  x;
	size_t  y;

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
		|| map_info->objects.exit_cnt != 1)
		return_error();
}
