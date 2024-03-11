/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woonshin <woonshin@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 14:02:51 by woonshin          #+#    #+#             */
/*   Updated: 2024/03/11 16:22:44 by woonshin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	enemy_move(t_game_info *game_info)
{
	int		i;
	int		nx;

	i = 0;
	while (i < game_info->enemy_cnt)
	{
		mlx_put_image_to_window(game_info->mlx, game_info->win, game_info->textures.tile,
				(game_info->enemy_info + i)->x * 64, (game_info->enemy_info + i)->y * 64);
		if (game_info->map_info.map[(game_info->enemy_info + i)->y][(game_info->enemy_info + i)->x] == 'C')
			mlx_put_image_to_window(game_info->mlx, game_info->win, game_info->textures.collection,
					(game_info->enemy_info + i)->x * 64 + 12, (game_info->enemy_info + i)->y * 64 + 12);
		nx = (game_info->enemy_info + i)->x;
		if ((game_info->enemy_info + i)->dir == RIGHT)
			nx++;
		else if ((game_info->enemy_info + i)->dir == LEFT)
			nx--;
		if (game_info->map_info.map[(game_info->enemy_info + i)->y][nx] == '1' ||
			game_info->map_info.map[(game_info->enemy_info + i)->y][nx] == 'E')
		{
			if ((game_info->enemy_info + i)->dir == RIGHT)
				(game_info->enemy_info + i)->dir = LEFT;
			else if ((game_info->enemy_info + i)->dir == LEFT)
				(game_info->enemy_info + i)->dir = RIGHT;
		}
		else
			(game_info->enemy_info + i)->x = nx;
		i++;
	}
}

void	player_render(t_game_info *game_info)
{
	t_object_info	*player_info;
	void			*player;
	int				num;

	num = get_frame(game_info->enemy_cnt);
	player = NULL;
	player_info = &game_info->player_info;
	player_info->img_state = (player_info->img_state + 1) % (num);
	if (player_info->dir == RIGHT)
	{
		if (0 <= player_info->img_state && player_info->img_state < (num / 2))
			player = game_info->textures.player_right_1;
		else
			player = game_info->textures.player_right_2;
	}
	else if (player_info->dir == LEFT)
	{
		if (0 <= player_info->img_state && player_info->img_state < (num / 2))
			player = game_info->textures.player_left_1;
		else
			player = game_info->textures.player_left_2;
	}
	mlx_put_image_to_window(game_info->mlx, game_info->win, game_info->textures.tile,
		game_info->player_info.x * 64, game_info->player_info.y * 64);
	mlx_put_image_to_window(game_info->mlx, game_info->win, player,
		game_info->player_info.x * 64, game_info->player_info.y * 64);
}

void	enemy_render(t_game_info *game_info)
{
	t_object_info	*enemy_info;
	void			*enemy;
	int				i;

	i = 0;
	while (i < game_info->enemy_cnt)
	{
		enemy_info = game_info->enemy_info + i;
		if (enemy_info->dir == RIGHT)
			enemy = game_info->textures.enemy_right;
		else if (enemy_info->dir == LEFT)
			enemy = game_info->textures.enemy_left;
		mlx_put_image_to_window(game_info->mlx, game_info->win, enemy,
			game_info->enemy_info[i].x * 64, game_info->enemy_info[i].y * 64);
		i++;
	}
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
	enemy_render(game_info);
	player_render(game_info);
	step_render(game_info, game_info->moved_cnt);
	if (is_collision(game_info))
		return_ko(game_info);
	if (game_info->player_info.img_state
		% (get_frame(game_info->enemy_cnt)) == 0)
	{
		game_info->player_info.img_state++;
		enemy_move(game_info);
	}
	return (0);
}
