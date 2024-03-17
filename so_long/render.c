/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woonshin <woonshin@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 14:02:51 by woonshin          #+#    #+#             */
/*   Updated: 2024/03/17 15:39:49 by woonshin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	player_render(t_game_info *game_info)
{
	t_object_info	*player_info;
	void			*player;

	player = NULL;
	player_info = &game_info->player_info;
	player_info->img_state = (player_info->img_state + 1) % (30);
	if (player_info->dir == RIGHT)
	{
		if (0 <= player_info->img_state && player_info->img_state < (30 / 2))
			player = game_info->textures.player_right_1;
		else
			player = game_info->textures.player_right_2;
	}
	else if (player_info->dir == LEFT)
	{
		if (0 <= player_info->img_state && player_info->img_state < (30 / 2))
			player = game_info->textures.player_left_1;
		else
			player = game_info->textures.player_left_2;
	}
	mlx_put_image_to_window(game_info->mlx, game_info->win,
		game_info->textures.tile,
		game_info->player_info.x * 64, game_info->player_info.y * 64);
	mlx_put_image_to_window(game_info->mlx, game_info->win, player,
		game_info->player_info.x * 64, game_info->player_info.y * 64);
}

void	map_render(t_game_info *game_info)
{
	int	x;
	int	y;

	y = 0;
	while ((size_t) y < game_info->map_info.height)
	{
		x = 0;
		while ((size_t) x < game_info->map_info.width)
		{
			mlx_put_image_to_window(game_info->mlx, game_info->win,
				game_info->textures.tile, x * 64, y * 64);
			if (game_info->map_info.map[y][x] == '1')
				mlx_put_image_to_window(game_info->mlx, game_info->win,
					game_info->textures.wall, x * 64, y * 64);
			else if (game_info->map_info.map[y][x] == 'E')
				mlx_put_image_to_window(game_info->mlx, game_info->win,
					game_info->textures.exit, x * 64, y * 64 + 36);
			else if (game_info->map_info.map[y][x] == 'C')
				mlx_put_image_to_window(game_info->mlx, game_info->win,
					game_info->textures.collection, x * 64 + 12, y * 64 + 12);
			x++;
		}
		y++;
	}
}

int	render(t_game_info *game_info)
{
	player_render(game_info);
	return (0);
}
