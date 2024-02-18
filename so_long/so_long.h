/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woonshin <woonshin@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 03:29:35 by woonshin          #+#    #+#             */
/*   Updated: 2024/02/18 15:56:06 by woonshin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
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

# include <stdio.h>

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

typedef struct	s_textures
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
}	t_textures;
typedef struct	s_object_info
{
	int		x;
	int		y;
	int		dir;
	int		img_state;
}	t_object_info;

typedef struct	s_game_info
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

void	create_enemy(t_game_info *game_info, int n);

void	return_error(void);
void	new_2d_array(char ***arr, int width, int height);

#endif