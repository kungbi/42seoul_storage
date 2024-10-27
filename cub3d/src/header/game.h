/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonyocho <wonyocho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 15:35:04 by woonshin          #+#    #+#             */
/*   Updated: 2024/10/11 19:29:42 by wonyocho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_H
# define GAME_H
# include "structs.h"
# include <math.h>

// loop.c
int		loop(t_system *sys);
void	buffer_clear(t_system *sys);
void	paint_background(t_system *sys);
void	raycasting(t_system *sys, int x);
void	paint(t_system *sys);
// events.c
int		key_hook(int keycode, t_system *sys);
int		exit_hook(t_system *sys);
void	move_ver(int dir, t_system *sys);
void	move_hor(int dir, t_system *sys);
void	move_cam(int dir, t_system *sys);
// draw_wall.c
void	draw_wall(t_system *sys, t_raycast *ray, int x);
int		get_tex_x(t_system *sys, t_raycast *ray);
void	draw_pixel(t_system *sys, t_raycast *ray, int x, int y);
int		get_tex_num(t_system *sys, t_raycast *ray);
// raycast.c
void	set_raycast_info(t_system *sys, t_raycast *ray, int x);
void	set_step_and_side_dist(t_system *sys, t_raycast *ray);
void	perform_dda(t_system *sys, t_raycast *ray);
void	calculate_wall_distance(t_system *sys, t_raycast *ray);

#endif
