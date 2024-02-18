/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woonshin <woonshin@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 01:17:14 by woonshin          #+#    #+#             */
/*   Updated: 2024/02/18 17:50:52 by woonshin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "so_long.h"

void	game_info_init(t_game_info *game_info);
void	textures_init(t_game_info *game_info);
void	map_info_init(t_map_info *map_info);

int	on_destroy(void)
{
	exit(0);
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
	{
		game_info->moved_cnt++;
		ft_putnbr_fd(game_info->moved_cnt, 1);
		exit(0);
	}
	else
		return (1);
	if (game_info->map_info.map[next_pos.y][next_pos.x] == '1')
		return (0);
	else if (game_info->map_info.map[next_pos.y][next_pos.x] == 'C')
	{
		game_info->map_info.map[next_pos.y][next_pos.x] = '0';
		game_info->collection_cnt++;
	}
	else if (game_info->map_info.map[next_pos.y][next_pos.x] == 'E')
	{
		if (game_info->collection_cnt == game_info->map_info.objects.collection_cnt)
			exit(0);
		return (0);
	}
	if (keycode == KEY_LEFT || keycode == KEY_RIGHT)
		game_info->player_info.dir = keycode;
	game_info->player_info.x = next_pos.x;
	game_info->player_info.y = next_pos.y;
	game_info->moved_cnt++;
	ft_putnbr_fd(game_info->moved_cnt, 1);
	ft_putstr_fd("\n", 1);
	return (0);
}

void	enemy_move(t_map_info *map_info, t_object_info *enemy_info, int n)
{
	int		i;
	int		nx;

	i = 0;
	while (i < n)
	{
		nx = (enemy_info + i)->x;
		if ((enemy_info + i)->dir == RIGHT)
			nx++;
		else if ((enemy_info + i)->dir == LEFT)
			nx--;

		if (map_info->map[(enemy_info + i)->y][nx] == '1')
		{
			if ((enemy_info + i)->dir == RIGHT)
				(enemy_info + i)->dir = LEFT;
			else if ((enemy_info + i)->dir == LEFT)
				(enemy_info + i)->dir = RIGHT;
		}
		else
			(enemy_info + i)->x = nx;
		i++;
	}
}

int	render(t_game_info *game_info)
{
	t_object_info	*player_info;
	void	*player;

	mlx_clear_window(game_info->mlx, game_info->win);

	for (int y = 0; y < game_info->map_info.height; y++)
	{
		for (int x = 0; x < game_info->map_info.width; x++)
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
		}
	}

	player_info = &game_info->player_info;
	player_info->img_state = (player_info->img_state + 1) % 30;
	if (player_info->dir == RIGHT)
	{
		if (0 <= player_info->img_state && player_info->img_state < 15)
			player = game_info->textures.player_right_1;
		else
			player = game_info->textures.player_right_2;
	}
	else if (player_info->dir == LEFT)
	{
		if (0 <= player_info->img_state && player_info->img_state < 15)
			player = game_info->textures.player_left_1;
		else
			player = game_info->textures.player_left_2;
	}
	mlx_put_image_to_window(game_info->mlx, game_info->win, player,
		game_info->player_info.x * 64, game_info->player_info.y * 64);

	if (player_info->img_state % 5 == 0)
		enemy_move(&game_info->map_info, game_info->enemy_info, game_info->enemy_cnt);


	t_object_info *enemy_info;
	void	*enemy;
	for(int i = 0; i < game_info->enemy_cnt; i++)
	{
		enemy_info = game_info->enemy_info + i;
		enemy_info->img_state = (enemy_info->img_state + 1) % 30;
		if (enemy_info->dir == RIGHT)
		{
			if (0 <= enemy_info->img_state && enemy_info->img_state < 15)
				enemy = game_info->textures.player_right_1;
			else
				enemy = game_info->textures.player_right_2;
		}
		else if (enemy_info->dir == LEFT)
		{
			if (0 <= enemy_info->img_state && enemy_info->img_state < 15)
				enemy = game_info->textures.player_left_1;
			else
				enemy = game_info->textures.player_left_2;
		}
		mlx_put_image_to_window(game_info->mlx, game_info->win, enemy,
			game_info->enemy_info[i].x * 64, game_info->enemy_info[i].y * 64);
	}
	return (0);
}

int	main(int argc, char *argv[])
{
	t_game_info	game_info;
	void		*mlx_win;

	if (argc != 2)
		return_error();
	if (ft_strncmp(&argv[1][ft_strlen(argv[1]) - 4], ".ber", 4) != 0)
		return_error();
	map_info_init(&game_info.map_info);
	map_input(&game_info.map_info, argv[1]);
	map_check(&game_info.map_info);
	game_info_init(&game_info);
	create_enemy(&game_info, 5);

	mlx_key_hook(game_info.win, key_control, &game_info);
	mlx_loop_hook(game_info.mlx, render, &game_info);
	mlx_hook(game_info.win, 17, 0, on_destroy, NULL);

	mlx_loop(game_info.mlx);
}

void	map_info_init(t_map_info *map_info)
{
	map_info->objects.collection_cnt = 0;
	map_info->objects.exit_cnt = 0;
	map_info->objects.player_cnt = 0;
}

void	game_info_init(t_game_info *game_info)
{
	game_info->mlx = mlx_init();
	game_info->win = mlx_new_window(game_info->mlx,
		64 * game_info->map_info.width,
		64 * game_info->map_info.height, "so_long");
	game_info->moved_cnt = 0;
	game_info->collection_cnt = 0;
	textures_init(game_info);
	game_info->player_info.dir = RIGHT;
	game_info->player_info.x = game_info->map_info.objects.player.x;
	game_info->player_info.y = game_info->map_info.objects.player.y;
	game_info->player_info.img_state = 0;
}

void	textures_init(t_game_info *game_info)
{
	int width;
	int height;

	width = 64;
	height = 64;
	game_info->textures.tile = 
		mlx_xpm_file_to_image(game_info->mlx, "./textures/tile.xpm", &width, &height);
	game_info->textures.wall = 
		mlx_xpm_file_to_image(game_info->mlx, "./textures/wall.xpm", &width, &height);
	game_info->textures.player_left_1 = 
		mlx_xpm_file_to_image(game_info->mlx, "./textures/left_1.xpm", &width, &height);
	game_info->textures.player_left_2 = 
		mlx_xpm_file_to_image(game_info->mlx, "./textures/left_2.xpm", &width, &height);
	game_info->textures.player_right_1 = 
		mlx_xpm_file_to_image(game_info->mlx, "./textures/right_1.xpm", &width, &height);
	game_info->textures.player_right_2 = 
		mlx_xpm_file_to_image(game_info->mlx, "./textures/right_2.xpm", &width, &height);
	game_info->textures.enemy = 
		mlx_xpm_file_to_image(game_info->mlx, "./textures/enemy.xpm", &width, &height);
	game_info->textures.exit = 
		mlx_xpm_file_to_image(game_info->mlx, "./textures/exit.xpm", &width, &height);
	game_info->textures.collection = 
		mlx_xpm_file_to_image(game_info->mlx, "./textures/collection.xpm", &width, &height);
}
