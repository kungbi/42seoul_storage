/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woonshin <woonshin@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 03:29:35 by woonshin          #+#    #+#             */
/*   Updated: 2024/02/16 09:55:47 by woonshin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include "get_next_line.h"
# include "libft.h"

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
}   t_map_info;

int		map_check(t_map_info *map_info);
void	map_input(t_map_info *map_info, char *filename);

void	return_error(void);

#endif