/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonyocho <wonyocho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 18:29:54 by wonyocho          #+#    #+#             */
/*   Updated: 2024/10/11 19:00:42 by wonyocho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structs.h"
#include "game.h"

void	set_raycast_info(t_system *sys, t_raycast *ray, int x)
{
	ray->info.camera_x = 2 * x / (double)SCREEN_WIDTH - 1;
	ray->info.ray_dir_x = sys->player.dir_x
		+ sys->player.plane_x * ray->info.camera_x;
	ray->info.ray_dir_y = sys->player.dir_y
		+ sys->player.plane_y * ray->info.camera_x;
	ray->calc.map_x = (int)sys->player.pos_x;
	ray->calc.map_y = (int)sys->player.pos_y;
	ray->calc.delta_dist_x = sqrt(1
			+ (ray->info.ray_dir_y * ray->info.ray_dir_y)
			/ (ray->info.ray_dir_x * ray->info.ray_dir_x));
	ray->calc.delta_dist_y = sqrt(1
			+ (ray->info.ray_dir_x * ray->info.ray_dir_x)
			/ (ray->info.ray_dir_y * ray->info.ray_dir_y));
	ray->calc.hit = 0;
}

void	set_step_and_side_dist(t_system *sys, t_raycast *ray)
{
	if (ray->info.ray_dir_x < 0)
	{
		ray->calc.step_x = -1;
		ray->calc.side_dist_x = (sys->player.pos_x - ray->calc.map_x)
			* ray->calc.delta_dist_x;
	}
	else
	{
		ray->calc.step_x = 1;
		ray->calc.side_dist_x = (ray->calc.map_x + 1.0 - sys->player.pos_x)
			* ray->calc.delta_dist_x;
	}
	if (ray->info.ray_dir_y < 0)
	{
		ray->calc.step_y = -1;
		ray->calc.side_dist_y = (sys->player.pos_y - ray->calc.map_y)
			* ray->calc.delta_dist_y;
	}
	else
	{
		ray->calc.step_y = 1;
		ray->calc.side_dist_y = (ray->calc.map_y + 1.0 - sys->player.pos_y)
			* ray->calc.delta_dist_y;
	}
}

void	perform_dda(t_system *sys, t_raycast *ray)
{
	while (ray->calc.hit == 0)
	{
		if (ray->calc.side_dist_x < ray->calc.side_dist_y)
		{
			ray->calc.side_dist_x += ray->calc.delta_dist_x;
			ray->calc.map_x += ray->calc.step_x;
			ray->calc.side = 0;
		}
		else
		{
			ray->calc.side_dist_y += ray->calc.delta_dist_y;
			ray->calc.map_y += ray->calc.step_y;
			ray->calc.side = 1;
		}
		if (sys->map[ray->calc.map_y][ray->calc.map_x] == '1')
			ray->calc.hit = 1;
	}
}

void	calculate_wall_distance(t_system *sys, t_raycast *ray)
{
	if (ray->calc.side == 0)
		ray->result.perp_wall_dist = (ray->calc.map_x - sys->player.pos_x
				+ (1 - ray->calc.step_x) / 2) / ray->info.ray_dir_x;
	else
		ray->result.perp_wall_dist = (ray->calc.map_y - sys->player.pos_y
				+ (1 - ray->calc.step_y) / 2) / ray->info.ray_dir_y;
	ray->result.line_height = (int)(SCREEN_HEIGHT / ray->result.perp_wall_dist);
	ray->result.draw_start = -ray->result.line_height / 2 + SCREEN_HEIGHT / 2;
	if (ray->result.draw_start < 0)
		ray->result.draw_start = 0;
	ray->result.draw_end = ray->result.line_height / 2 + SCREEN_HEIGHT / 2;
	if (ray->result.draw_end >= SCREEN_HEIGHT)
		ray->result.draw_end = SCREEN_HEIGHT - 1;
}
