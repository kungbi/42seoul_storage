/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woonshin <woonshin@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 01:17:14 by woonshin          #+#    #+#             */
/*   Updated: 2024/02/16 10:39:58 by woonshin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "so_long.h"

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
void	map_info_init(t_map_info *map_info);

int main(int argc, char *argv[])
{
	t_map_info	map_info;

	if (argc != 2)
		return (1);
	map_info_init(&map_info);
	map_input(&map_info, argv[1]);
	map_check(&map_info);
	
    // void	*mlx;
	// void	*mlx_win;
	// t_data	img;

	// mlx = mlx_init();
	// mlx_win = mlx_new_window(mlx, 500, 500, "Hello world!");
	// img.img = mlx_new_image(mlx, 500, 500);
	// img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
	// 							&img.endian);
	// my_mlx_pixel_put(&img, 5, 5, 0x00FF0000);
	// mlx_put_image_to_window(mlx, mlx_win, img.img, 10, 10);
	// mlx_loop(mlx);
    // return (0);
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void	map_info_init(t_map_info *map_info)
{
	map_info->height = 0;
	map_info->width = -1;
	map_info->objects.collection_cnt = 0;
	map_info->objects.exit_cnt = 0;
	map_info->objects.player_cnt = 0;
}
