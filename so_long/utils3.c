/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woonshin <woonshin@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 17:16:43 by woonshin          #+#    #+#             */
/*   Updated: 2024/03/12 17:18:45 by woonshin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	clean_enemy_pos(t_game_info *game_info, int i)
{
	t_object_info	*enemy_info;
	char			**map;

	enemy_info = game_info->enemy_info;
	map = game_info->map_info.map;
	mlx_put_image_to_window(game_info->mlx,
		game_info->win, game_info->textures.tile,
		enemy_info[i].x * 64, enemy_info[i].y * 64);
	if (map[enemy_info[i].y][enemy_info[i].x] == 'C')
		mlx_put_image_to_window(game_info->mlx, game_info->win,
			game_info->textures.collection,
			enemy_info[i].x * 64 + 12, enemy_info[i].y * 64 + 12);
}
