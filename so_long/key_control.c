/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_control.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woonshin <woonshin@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 14:17:17 by woonshin          #+#    #+#             */
/*   Updated: 2024/03/17 16:33:30 by woonshin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move(t_game_info *game_info, t_pos *next_pos);

int	is_next_pos_available(t_game_info *game_info, t_pos *next_pos)
{
	if (game_info->map_info.map[next_pos->y][next_pos->x] == '1')
		return (-1);
	else if (game_info->map_info.map[next_pos->y][next_pos->x] == 'C')
	{
		game_info->map_info.map[next_pos->y][next_pos->x] = '0';
		game_info->collection_cnt++;
	}
	else if (game_info->map_info.map[next_pos->y][next_pos->x] == 'E')
	{
		if ((size_t) game_info->collection_cnt
			== game_info->map_info.objects.collection_cnt)
		{
			move(game_info, next_pos);
			return_ok(game_info);
		}
		return (-1);
	}
	return (1);
}

void	move(t_game_info *game_info, t_pos *next_pos)
{
	mlx_put_image_to_window(game_info->mlx, game_info->win,
		game_info->textures.tile,
		game_info->player_info.x * 64, game_info->player_info.y * 64);
	game_info->player_info.x = next_pos->x;
	game_info->player_info.y = next_pos->y;
	game_info->moved_cnt++;
	ft_putnbr_fd(game_info->moved_cnt, 1);
	ft_putstr_fd("\n", 1);
}

int	key_control(int keycode, t_game_info *game_info)
{
	t_pos	next_pos;

	next_pos.x = game_info->player_info.x;
	next_pos.y = game_info->player_info.y;
	if (keycode == KEY_RIGHT)
		next_pos.x++;
	else if (keycode == KEY_LEFT)
		next_pos.x--;
	else if (keycode == KEY_UP)
		next_pos.y--;
	else if (keycode == KEY_DOWN)
		next_pos.y++;
	else if (keycode == KEY_ESC)
		on_destroy(game_info, 0);
	else
		return (1);
	if (keycode == KEY_LEFT || keycode == KEY_RIGHT)
		game_info->player_info.dir = keycode;
	if (is_next_pos_available(game_info, &next_pos) != 1)
		return (0);
	move(game_info, &next_pos);
	return (0);
}
