/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woonshin <woonshin@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 01:17:14 by woonshin          #+#    #+#             */
/*   Updated: 2024/03/31 09:17:36 by woonshin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char *argv[])
{
	t_game_info	game_info;

	if (argc != 2)
		return_error();
	if (ft_strncmp(&argv[1][ft_strlen(argv[1]) - 4], ".ber", 4) != 0)
		return_error();
	map_info_init(&game_info.map_info);
	map_input(&game_info.map_info, argv[1]);
	map_check(&game_info.map_info);
	game_info_init(&game_info);
	map_render(&game_info);
	mlx_key_hook(game_info.win, key_control, &game_info);
	mlx_loop_hook(game_info.mlx, render, &game_info);
	mlx_hook(game_info.win, EXIT_EVENT, 0, on_destroy, &game_info);
	mlx_loop(game_info.mlx);
	exit(0);
}

void	map_info_init(t_map_info *map_info)
{
	map_info->width = -1;
	map_info->height = 0;
	map_info->objects.collection_cnt = 0;
	map_info->objects.exit_cnt = 0;
	map_info->objects.player_cnt = 0;
}

int	get_frame(int x)
{
	if (30 <= x)
		return (10);
	return (30 - x);
}
