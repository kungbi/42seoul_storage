/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   step_render_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woonshin <woonshin@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 14:04:43 by woonshin          #+#    #+#             */
/*   Updated: 2024/02/29 14:36:10 by woonshin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	step_render_low_num(t_game_info *game_info, int x, char c)
{
	if (c == '0')
		mlx_put_image_to_window(game_info->mlx, game_info->win,
			game_info->textures.number_0, (x + 1) * 32, 32);
	else if (c == '1')
		mlx_put_image_to_window(game_info->mlx, game_info->win,
			game_info->textures.number_1, (x + 1) * 32, 32);
	else if (c == '2')
		mlx_put_image_to_window(game_info->mlx, game_info->win,
			game_info->textures.number_2, (x + 1) * 32, 32);
	else if (c == '3')
		mlx_put_image_to_window(game_info->mlx, game_info->win,
			game_info->textures.number_3, (x + 1) * 32, 32);
	else if (c == '4')
		mlx_put_image_to_window(game_info->mlx, game_info->win,
			game_info->textures.number_4, (x + 1) * 32, 32);
}

void	step_render_high_num(t_game_info *game_info, int x, char c)
{
	if (c == '5')
		mlx_put_image_to_window(game_info->mlx, game_info->win,
			game_info->textures.number_5, (x + 1) * 32, 32);
	else if (c == '6')
		mlx_put_image_to_window(game_info->mlx, game_info->win,
			game_info->textures.number_6, (x + 1) * 32, 32);
	else if (c == '7')
		mlx_put_image_to_window(game_info->mlx, game_info->win,
			game_info->textures.number_7, (x + 1) * 32, 32);
	else if (c == '8')
		mlx_put_image_to_window(game_info->mlx, game_info->win,
			game_info->textures.number_8, (x + 1) * 32, 32);
	else if (c == '9')
		mlx_put_image_to_window(game_info->mlx, game_info->win,
			game_info->textures.number_9, (x + 1) * 32, 32);
}

void	step_render(t_game_info *game_info, int num)
{
	char	*str_num;
	int		x;

	x = 0;
	str_num = ft_itoa(num);
	if (str_num == NULL)
		return_error();
	while (str_num[x] != '\0')
	{
		if ('0' <= str_num[x] && str_num[x] <= '4')
			step_render_low_num(game_info, x, str_num[x]);
		else
			step_render_high_num(game_info, x, str_num[x]);
		x++;
	}
	free(str_num);
}
