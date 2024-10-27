/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woonshin <woonshin@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 12:47:52 by woonshin          #+#    #+#             */
/*   Updated: 2024/10/12 19:28:50 by woonshin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "structs.h"
#include "game.h"
#include <stdlib.h>
#include <stdio.h>

int	key_hook(int keycode, t_system *sys)
{
	if (keycode == KEY_ESC)
		exit_hook(sys);
	else if (keycode == KEY_W)
		move_ver(FRONT, sys);
	else if (keycode == KEY_S)
		move_ver(BACK, sys);
	else if (keycode == KEY_A)
		move_hor(LEFT, sys);
	else if (keycode == KEY_D)
		move_hor(RIGHT, sys);
	else if (keycode == KEY_RIGHT)
		move_cam(RIGHT, sys);
	else if (keycode == KEY_LEFT)
		move_cam(LEFT, sys);
	else
		return (0);
	loop(sys);
	return (0);
}

int	exit_hook(t_system *sys)
{
	mlx_destroy_window(sys->graphics.mlx, sys->graphics.win);
	exit(0);
}

void	move_ver(int dir, t_system *sys)
{
	double	move_x;
	double	move_y;
	double	x_comp;
	double	y_comp;

	if (dir == BACK)
	{
		move_x = -sys->player.dir_x * MOVE_SPEED;
		x_comp = -sys->player.dir_x * MOVE_SPEED;
		move_y = -sys->player.dir_y * MOVE_SPEED;
		y_comp = -sys->player.dir_y * MOVE_SPEED;
	}
	else
	{
		move_x = sys->player.dir_x * MOVE_SPEED;
		x_comp = sys->player.dir_x * MOVE_SPEED;
		move_y = sys->player.dir_y * MOVE_SPEED;
		y_comp = sys->player.dir_y * MOVE_SPEED;
	}
	if (sys->map[(int)(sys->player.pos_y + y_comp)][(int)(sys->player.pos_x \
		+ move_x + x_comp)] != '1')
		sys->player.pos_x += move_x;
	if (sys->map[(int)(sys->player.pos_y + move_y + y_comp) \
		][(int)(sys->player.pos_x + x_comp)] != '1')
		sys->player.pos_y += move_y;
}

void	move_hor(int dir, t_system *sys)
{
	double	next_pos_x;
	double	next_pos_y;

	if (dir == LEFT)
	{
		next_pos_x = sys->player.pos_x - sys->player.plane_x * MOVE_SPEED;
		next_pos_y = sys->player.pos_y - sys->player.plane_y * MOVE_SPEED;
	}
	else if (dir == RIGHT)
	{
		next_pos_x = sys->player.pos_x + sys->player.plane_x * MOVE_SPEED;
		next_pos_y = sys->player.pos_y + sys->player.plane_y * MOVE_SPEED;
	}
	if (sys->map[(int)(next_pos_y)][(int)(sys->player.pos_x)] != '1')
		sys->player.pos_y = next_pos_y;
	if (sys->map[(int)(sys->player.pos_y)][(int)(next_pos_x)] != '1')
		sys->player.pos_x = next_pos_x;
}

void	move_cam(int dir, t_system *sys)
{
	double	olddir_x;
	double	oldplane_x;
	double	tmp_rot_speed;

	olddir_x = sys->player.dir_x;
	oldplane_x = sys->player.plane_x;
	tmp_rot_speed = -ROT_SPEED;
	if (dir == RIGHT)
		tmp_rot_speed = ROT_SPEED;
	sys->player.dir_x = sys->player.dir_x * cos(tmp_rot_speed) - \
		sys->player.dir_y * sin(tmp_rot_speed);
	sys->player.dir_y = olddir_x * sin(tmp_rot_speed) + \
		sys->player.dir_y * cos(tmp_rot_speed);
	sys->player.plane_x = sys->player.plane_x * cos(tmp_rot_speed) - \
		sys->player.plane_y * sin(tmp_rot_speed);
	sys->player.plane_y = oldplane_x * sin(tmp_rot_speed) + \
		sys->player.plane_y * cos(tmp_rot_speed);
}
