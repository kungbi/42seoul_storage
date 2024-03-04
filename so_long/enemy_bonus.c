/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woonshin <woonshin@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 15:35:09 by woonshin          #+#    #+#             */
/*   Updated: 2024/03/04 20:32:54 by woonshin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	put_enemy_to_map(t_game_info *game_info, int n);
int	set_enemy_count(t_map_info *map_info);
int	get_value_n_free(int *arr, int idx);

void	create_enemy(t_game_info *game_info)
{
	int	i;
	int	d;
	int	n;

	n = set_enemy_count(&game_info->map_info);
	game_info->enemy_info = ft_calloc(n, sizeof(t_object_info));
	if (game_info->enemy_info == NULL)
		return_error();
	game_info->enemy_cnt = put_enemy_to_map(game_info, n);
	i = -1;
	while (++i < game_info->enemy_cnt)
	{
		d = rand() % 2;
		if (d == 0)
			game_info->enemy_info[i].dir = LEFT;
		else if (d == 1)
			game_info->enemy_info[i].dir = RIGHT;
	}
}

int	set_enemy_count(t_map_info *map_info)
{
	int	x;
	int	y;
	int	empty_cnt;

	x = 0;
	y = 0;
	empty_cnt = 0;
	while ((size_t) y < map_info->height)
	{
		x = 0;
		while ((size_t) x < map_info->width)
		{
			if (map_info->map[y][x] == '0')
				empty_cnt++;
			x++;
		}
		y++;
	}
	return (empty_cnt / 20);
}

int	get_empty_x_rand(t_map_info *map_info, int y)
{
	int	empty_cnt;
	int	x;
	int	i;
	int	*empty_pos_list;

	empty_cnt = 0;
	x = 0;
	while ((size_t) x < map_info->width)
	{
		if (map_info->map[y][x] == '0')
			empty_cnt++;
		x++;
	}
	empty_pos_list = ft_calloc(empty_cnt, sizeof(int));
	if (empty_pos_list == NULL)
		return_error();
	i = 0;
	x = -1;
	while ((size_t)(++x) < map_info->width)
		if (map_info->map[y][x] == '0')
			empty_pos_list[i++] = x;
	if (0 < empty_cnt)
		return (get_value_n_free(empty_pos_list, rand() % empty_cnt));
	return (free(empty_pos_list), -1);
}

int	put_enemy_to_map(t_game_info *game_info, int n)
{
	int	y;
	int	x;
	int	i;

	y = -1;
	i = 0;
	while (i < n)
	{
		while ((size_t)(++y) < game_info->map_info.height)
		{
			if ((size_t) y == game_info->map_info.objects.player.y)
				continue ;
			x = get_empty_x_rand(&game_info->map_info, y);
			if (x != -1 && i < n)
			{
				game_info->enemy_info[i].x = x;
				game_info->enemy_info[i].y = y;
				game_info->map_info.map[y][x] = 'e';
				i++;
			}
			y += 1 + rand() % 1;
		}
		y = 0;
	}
	return (i);
}

int	get_value_n_free(int *arr, int idx)
{
	int	num;

	num = arr[idx];
	free(arr);
	return (idx);
}
