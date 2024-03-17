/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woonshin <woonshin@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 13:16:09 by woonshin          #+#    #+#             */
/*   Updated: 2024/03/17 16:49:02 by woonshin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	on_destroy(t_game_info *game_info, int print)
{
	game_free(game_info);
	if (print == 1)
	{
		ft_putnbr_fd(game_info->moved_cnt, 1);
		ft_putchar_fd('\n', 1);
	}
	exit(0);
}

void	game_info_init(t_game_info *game_info)
{
	game_info->mlx = mlx_init();
	game_info->win = mlx_new_window(game_info->mlx,
			64 * game_info->map_info.width,
			64 * game_info->map_info.height, "so_long_bonus");
	game_info->moved_cnt = 0;
	game_info->collection_cnt = 0;
	textures_init(game_info);
	game_info->player_info.dir = RIGHT;
	game_info->player_info.x = game_info->map_info.objects.player.x;
	game_info->player_info.y = game_info->map_info.objects.player.y;
	game_info->player_info.img_state = 0;
}

void	*get_img(t_game_info *game_info, char *filename)
{
	int	width;
	int	height;

	width = 64;
	height = 64;
	return (mlx_xpm_file_to_image(game_info->mlx, filename, &width, &height));
}

void	textures_init(t_game_info *game_info)
{
	t_textures	*textures;

	textures = &game_info->textures;
	textures->tile = get_img(game_info, "./textures/tile.xpm");
	textures->wall = get_img(game_info, "./textures/wall.xpm");
	textures->player_left_1 = get_img(game_info, "./textures/left_1.xpm");
	textures->player_left_2 = get_img(game_info, "./textures/left_2.xpm");
	textures->player_right_1 = get_img(game_info, "./textures/right_1.xpm");
	textures->player_right_2 = get_img(game_info, "./textures/right_2.xpm");
	textures->enemy = get_img(game_info, "./textures/enemy.xpm");
	textures->exit = get_img(game_info, "./textures/exit.xpm");
	textures->collection = get_img(game_info, "./textures/collection.xpm");
	textures->enemy_left = get_img(game_info, "./textures/enemy_left.xpm");
	textures->enemy_right = get_img(game_info, "./textures/enemy_right.xpm");
	textures->number_0 = get_img(game_info, "./textures/number_0.xpm");
	textures->number_1 = get_img(game_info, "./textures/number_1.xpm");
	textures->number_2 = get_img(game_info, "./textures/number_2.xpm");
	textures->number_3 = get_img(game_info, "./textures/number_3.xpm");
	textures->number_4 = get_img(game_info, "./textures/number_4.xpm");
	textures->number_5 = get_img(game_info, "./textures/number_5.xpm");
	textures->number_6 = get_img(game_info, "./textures/number_6.xpm");
	textures->number_7 = get_img(game_info, "./textures/number_7.xpm");
	textures->number_8 = get_img(game_info, "./textures/number_8.xpm");
	textures->number_9 = get_img(game_info, "./textures/number_9.xpm");
	textures->number_back = get_img(game_info, "./textures/number_back.xpm");
}

void	free_2d_array(char **array, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		free(array[i]);
		i++;
	}
	free(array);
}
