/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woonshin <woonshin@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 14:54:18 by woonshin          #+#    #+#             */
/*   Updated: 2024/10/12 19:24:45 by woonshin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structs.h"
#include "utils.h"
#include "libft.h"
#include "error.h"
#include "mlx.h"

void	init_player(t_system *sys);
void	load_textures(t_system *sys);

void	init_system(t_system *sys)
{
	int	i;

	ft_memset(sys, 0, sizeof(t_system));
	i = 0;
	while (i < 3)
	{
		sys->components.f[i] = -1;
		sys->components.c[i] = -1;
		i++;
	}
	sys->graphics.buf = (int **)ft_calloc(SCREEN_HEIGHT, sizeof(int *));
	if (!sys->graphics.buf)
		error_exit(MALLOC_ERROR);
	i = 0;
	while (i < SCREEN_HEIGHT)
	{
		sys->graphics.buf[i] = (int *)ft_calloc(SCREEN_WIDTH, sizeof(int));
		if (!sys->graphics.buf[i])
			error_exit(MALLOC_ERROR);
		i++;
	}
}

void	init_raycast(t_system *sys)
{
	init_player(sys);
	load_textures(sys);
}

void	put_mlx_img(t_system *sys, char *path, t_img *img)
{
	int	wid;
	int	hei;

	img->img = mlx_xpm_file_to_image(sys->graphics.mlx, path, &wid, &hei);
	if (!img->img)
		error_exit(ERROR);
	img->data = (int *)mlx_get_data_addr(img->img, &(img->bpp), \
		&(img->size_l), &(img->endian));
	if (!img->data)
		error_exit(ERROR);
}

void	load_textures(t_system *sys)
{
	int		i;
	void	*img;

	put_mlx_img(sys, sys->components.no, &sys->graphics.textures[0]);
	put_mlx_img(sys, sys->components.so, &sys->graphics.textures[1]);
	put_mlx_img(sys, sys->components.we, &sys->graphics.textures[2]);
	put_mlx_img(sys, sys->components.ea, &sys->graphics.textures[3]);
}

void	init_player(t_system *sys)
{
	sys->player.pos_x = (double) sys->player.x + 0.5;
	sys->player.pos_y = (double) sys->player.y + 0.5;
	if (sys->player.dir == 'N')
	{
		sys->player.dir_y = -1;
		sys->player.plane_x = 0.66;
	}
	else if (sys->player.dir == 'S')
	{
		sys->player.dir_y = 1;
		sys->player.plane_x = -0.66;
	}
	else if (sys->player.dir == 'W')
	{
		sys->player.dir_x = -1;
		sys->player.plane_y = -0.66;
	}
	else if (sys->player.dir == 'E')
	{
		sys->player.dir_x = 1;
		sys->player.plane_y = 0.66;
	}
}
