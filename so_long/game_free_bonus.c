/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_free_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woonshin <woonshin@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 20:45:51 by woonshin          #+#    #+#             */
/*   Updated: 2024/03/04 20:49:18 by woonshin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	game_free(t_game_info *game_info)
{
	size_t	i;

	i = 0;
	while (i < game_info->map_info.height)
	{
		free(game_info->map_info.map[i]);
		i++;
	}
	free(game_info->map_info.map);
	mlx_destroy_window(game_info->mlx, game_info->win);
}
