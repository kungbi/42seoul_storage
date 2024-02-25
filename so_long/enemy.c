/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woonshin <woonshin@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 15:35:09 by woonshin          #+#    #+#             */
/*   Updated: 2024/02/25 15:22:43 by woonshin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	put_enemy_to_map(t_game_info *game_info, int n);

void	create_enemy(t_game_info *game_info, int n)
{
	int	i;

	game_info->enemy_info = ft_calloc(n, sizeof(t_object_info));
	if (game_info->enemy_info == NULL)
		return_error();
	game_info->enemy_cnt = put_enemy_to_map(game_info, n);
	i = -1;
	while (++i < game_info->enemy_cnt)
		game_info->enemy_info[i].dir = RIGHT;
}

int	put_enemy_to_map(t_game_info *game_info, int n)
{
	int	y;
	int	x;
	int	i;

	y = -1;
	i = 0;
	while ((size_t)(++y) < game_info->map_info.height && i < n)
	{
		if ((size_t) y == game_info->map_info.objects.player.y)
			continue ;
		x = -1;
		while ((size_t)(++x) < game_info->map_info.width)
		{
			if (game_info->map_info.map[y][x] == '0')
			{
				game_info->enemy_info[i].x = x;
				game_info->enemy_info[i].y = y;
				i++;
				y++;
				break ;
			}
		}
	}
	return (i);
}
