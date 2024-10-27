/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_wall.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woonshin <woonshin@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 18:32:11 by wonyocho          #+#    #+#             */
/*   Updated: 2024/10/27 23:49:38 by woonshin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structs.h"
#include "game.h"

void	draw_wall(t_system *sys, t_raycast *ray, int x)
{
	int		y;

	ray->draw.tex_x = get_tex_x(sys, ray);
	ray->draw.step = 1.0 * TEXTURE_HEIGHT / ray->result.line_height;
	ray->draw.tex_pos = (ray->result.draw_start - SCREEN_HEIGHT / 2
			+ ray->result.line_height / 2) * ray->draw.step;
	y = ray->result.draw_start;
	while (y < ray->result.draw_end)
	{
		draw_pixel(sys, ray, x, y);
		y++;
	}
}

void	draw_pixel(t_system *sys, t_raycast *ray, int x, int y)
{
	int		tex_y;
	int		color;
	int		tex_num;

	tex_y = (int)(ray->draw.tex_pos) & (TEXTURE_HEIGHT - 1);
	ray->draw.tex_pos += ray->draw.step;
	if (ray->calc.side == 0)
	{
		if (sys->player.pos_x < ray->calc.map_x)
			tex_num = EAST;
		else
			tex_num = WEST;
	}
	else
	{
		if (sys->player.pos_y < ray->calc.map_y)
			tex_num = SOUTH;
		else
			tex_num = NORTH;
	}
	color = sys->graphics.textures[tex_num].data[TEXTURE_HEIGHT
		* tex_y + ray->draw.tex_x];
	if (ray->calc.side == 0)
		color = (color >> 1) & 8355711;
	sys->graphics.buf[y][x] = color;
}

int	get_tex_x(t_system *sys, t_raycast *ray)
{
	double	wall_x;
	int		tex_x;

	wall_x = 0;
	tex_x = 0;
	if (ray->calc.side == 0)
		wall_x = sys->player.pos_y + ray->result.perp_wall_dist
			* ray->info.ray_dir_y;
	else
		wall_x = sys->player.pos_x + ray->result.perp_wall_dist
			* ray->info.ray_dir_x;
	wall_x -= floor(wall_x);
	tex_x = (int)(wall_x * (double)TEXTURE_WIDTH);
	if (ray->calc.side == 0 && ray->info.ray_dir_x < 0)
		tex_x = TEXTURE_WIDTH - tex_x - 1;
	if (ray->calc.side == 1 && ray->info.ray_dir_y > 0)
		tex_x = TEXTURE_WIDTH - tex_x - 1;
	return (tex_x);
}
