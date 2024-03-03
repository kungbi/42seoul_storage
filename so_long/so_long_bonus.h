/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woonshin <woonshin@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 03:29:35 by woonshin          #+#    #+#             */
/*   Updated: 2024/03/03 20:28:23 by woonshin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H
# include <mlx.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include "get_next_line.h"
# include "libft.h"
# define KEY_UP 126
# define KEY_DOWN 125
# define KEY_LEFT 123
# define KEY_RIGHT 124
# define LEFT 123
# define RIGHT 124
# define KEY_ESC 53

typedef struct s_pos
{
	size_t	x;
	size_t	y;
}	t_pos;

typedef struct s_objects
{
	size_t	collection_cnt;
	size_t	exit_cnt;
	size_t	player_cnt;
	t_pos	player;
}	t_objects;

typedef struct s_map_info
{
	size_t		width;
	size_t		height;
	char		**map;
	t_objects	objects;
}	t_map_info;

typedef struct s_textures
{
	void	*tile;
	void	*wall;
	void	*player_left_1;
	void	*player_left_2;
	void	*player_right_1;
	void	*player_right_2;
	void	*enemy;
	void	*exit;
	void	*collection;
	void	*enemy_left;
	void	*enemy_right;
	void	*number_0;
	void	*number_1;
	void	*number_2;
	void	*number_3;
	void	*number_4;
	void	*number_5;
	void	*number_6;
	void	*number_7;
	void	*number_8;
	void	*number_9;
}	t_textures;
typedef struct s_object_info
{
	int		x;
	int		y;
	int		dir;
	int		img_state;
}	t_object_info;

typedef struct s_game_info
{
	void			*mlx;
	void			*win;
	t_map_info		map_info;
	t_object_info	player_info;
	t_object_info	*enemy_info;
	int				enemy_cnt;
	int				game_state;
	int				moved_cnt;
	t_textures		textures;
	int				collection_cnt;
}	t_game_info;

int		map_check(t_map_info *map_info);
void	map_input(t_map_info *map_info, char *filename);
int		is_collision(t_game_info *game_info);
void	create_enemy(t_game_info *game_info);

int		key_control(int keycode, t_game_info *game_info);

int		render(t_game_info *game_info);
void	step_render(t_game_info *game_info, int num);

void	return_error(void);
void	return_ok(void);
void	return_ko(void);
void	new_2d_array(char ***arr, int width, int height);
int		is_frame(t_map_info *map_info, int x, int y);

int		on_destroy(t_game_info *game_info);
void	textures_init(t_game_info *game_info);
void	map_info_init(t_map_info *map_info);
void	game_info_init(t_game_info *game_info);

void	free_2d_array(char **array, int n);
int		get_frame(int x);

#endif
