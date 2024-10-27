/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woonshin <woonshin@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 12:47:21 by woonshin          #+#    #+#             */
/*   Updated: 2024/10/12 15:56:32 by woonshin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
#include "mlx.h"
#include "libft.h"
#include "utils.h"

int	loop(t_system *sys)
{
	int	x;

	buffer_clear(sys);
	paint_background(sys);
	x = 0;
	while (x < SCREEN_WIDTH)
	{
		raycasting(sys, x);
		x++;
	}
	paint(sys);
	return (0);
}

void	buffer_clear(t_system *sys)
{
	int	y;
	int	x;

	y = 0;
	while (y < SCREEN_HEIGHT)
	{
		x = 0;
		while (x < SCREEN_WIDTH)
		{
			sys->graphics.buf[y][x] = 0;
			x++;
		}
		y++;
	}
}

void	paint_background(t_system *sys)
{
	int	y;
	int	x;

	y = -1;
	while (++y < SCREEN_HEIGHT / 2)
	{
		x = 0;
		while (x < SCREEN_WIDTH)
		{
			sys->graphics.buf[y][x] = sys->components.c[0] << 16
				| sys->components.c[1] << 8 | sys->components.c[2];
			x++;
		}
	}
	while (y < SCREEN_HEIGHT)
	{
		x = 0;
		while (x < SCREEN_WIDTH)
		{
			sys->graphics.buf[y][x] = sys->components.f[0] << 16
				| sys->components.f[1] << 8 | sys->components.f[2];
			x++;
		}
		y++;
	}
}

void	raycasting(t_system *sys, int x)
{
	t_raycast	*ray;

	ray = &sys->ray;
	set_raycast_info(sys, ray, x);
	set_step_and_side_dist(sys, ray);
	perform_dda(sys, ray);
	calculate_wall_distance(sys, ray);
	draw_wall(sys, ray, x);
}

void	paint(t_system *sys)
{
	int	y;
	int	x;

	y = 0;
	while (y < SCREEN_HEIGHT)
	{
		x = 0;
		while (x < SCREEN_WIDTH)
		{
			sys->graphics.screen.data[y * SCREEN_WIDTH + x]
				= sys->graphics.buf[y][x];
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(sys->graphics.mlx,
		sys->graphics.win, sys->graphics.screen.img, 0, 0);
}
