/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonyocho <wonyocho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 13:04:57 by woonshin          #+#    #+#             */
/*   Updated: 2024/10/11 19:19:37 by wonyocho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

# define X_BUTTON	17
# define X_EVENT_KEY_PRESS	2
# define KEY_ESC	53
# define KEY_W		13
# define KEY_A		0
# define KEY_S		1
# define KEY_D		2
# define KEY_RIGHT	124
# define KEY_LEFT	123

# define SCREEN_WIDTH 1400
# define SCREEN_HEIGHT 720
# define TEXTURE_WIDTH 64
# define TEXTURE_HEIGHT 64
# define TEXTURE_NUM 4

# define MOVE_SPEED	0.05
# define ROT_SPEED	0.05

# define NORTH 0
# define SOUTH 1
# define WEST 2
# define EAST 3

typedef enum e_arrow
{
	FRONT,
	BACK,
	LEFT,
	RIGHT
}	t_arrow;

typedef struct s_components
{
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
	int		f[3];
	int		c[3];
}	t_components;

typedef struct s_player
{
	int		x;
	int		y;
	char	dir;
	double	pos_x;
	double	pos_y;
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;
}	t_player;

typedef struct s_raycast_info
{
	double	camera_x;
	double	ray_dir_x;
	double	ray_dir_y;
}	t_raycast_info;

typedef struct s_raycast_calc
{
	int		map_x;
	int		map_y;
	double	side_dist_x;
	double	side_dist_y;
	double	delta_dist_x;
	double	delta_dist_y;
	int		step_x;
	int		step_y;
	int		hit;
	int		side;
}	t_raycast_calc;

typedef struct s_raycast_result
{
	double	perp_wall_dist;
	int		line_height;
	int		draw_start;
	int		draw_end;
	double	wall_x;
}	t_raycast_result;

typedef struct s_raycast_draw
{
	int		tex_x;
	double	step;
	double	tex_pos;
}	t_raycast_draw;

typedef struct s_raycast
{
	t_raycast_info		info;
	t_raycast_calc		calc;
	t_raycast_result	result;
	t_raycast_draw		draw;
}	t_raycast;

typedef struct s_img
{
	void	*img;
	char	*path;
	int		*data;
	int		bpp;
	int		size_l;
	int		endian;
}	t_img;

typedef struct s_graphics
{
	void	*mlx;
	void	*win;
	t_img	screen;
	t_img	textures[TEXTURE_NUM];
	int		**buf;
}	t_graphics;

typedef struct s_system
{
	t_components	components;
	t_player		player;
	t_raycast		ray;
	char			**map;
	t_graphics		graphics;
}	t_system;

#endif
