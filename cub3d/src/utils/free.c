/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woonshin <woonshin@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 15:24:31 by woonshin          #+#    #+#             */
/*   Updated: 2024/10/12 15:29:08 by woonshin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "mlx.h"
#include <stdlib.h>

void	free_graphics(t_system *sys)
{
	int	i;

	i = 0;
	while (i < TEXTURE_NUM)
	{
		mlx_destroy_image(sys->graphics.mlx, sys->graphics.textures[i].img);
		i++;
	}
	mlx_destroy_image(sys->graphics.mlx, sys->graphics.screen.img);
	mlx_destroy_window(sys->graphics.mlx, sys->graphics.win);
}

void	free_system(t_system *sys)
{
	free_components(&sys->components);
	if (sys->map)
		arr_2nd_free(sys->map);
	if (sys->graphics.buf)
		arr_2nd_free((char **)sys->graphics.buf);
}

void	free_components(t_components *components)
{
	if (components->no)
		free(components->no);
	if (components->so)
		free(components->so);
	if (components->we)
		free(components->we);
	if (components->ea)
		free(components->ea);
}
