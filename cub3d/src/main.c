/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woonshin <woonshin@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 13:03:09 by woonshin          #+#    #+#             */
/*   Updated: 2024/10/12 19:29:46 by woonshin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structs.h"
#include "parse.h"
#include "error.h"
#include "libft.h"
#include "utils.h"
#include "mlx.h"
#include "game.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
	t_system	sys;

	if (argc != 2)
		error_exit(ARG_ERROR);
	init_system(&sys);
	parse(&sys, argv[1]);
	sys.graphics.mlx = mlx_init();
	if (!sys.graphics.mlx)
		error_exit(GAME_ERROR);
	init_raycast(&sys);
	sys.graphics.win = mlx_new_window(sys.graphics.mlx, SCREEN_WIDTH, \
		SCREEN_HEIGHT, "cub3D");
	sys.graphics.screen.img = \
		mlx_new_image(sys.graphics.mlx, SCREEN_WIDTH, SCREEN_HEIGHT);
	sys.graphics.screen.data = \
		(int *)mlx_get_data_addr(sys.graphics.screen.img, \
		&(sys.graphics.screen.bpp), &(sys.graphics.screen.size_l),
			&(sys.graphics.screen.endian));
	loop(&sys);
	mlx_hook(sys.graphics.win, X_BUTTON, 0, &exit_hook, &sys);
	mlx_hook(sys.graphics.win, X_EVENT_KEY_PRESS, 0, &key_hook, &sys);
	mlx_loop(sys.graphics.mlx);
	free_graphics(&sys);
	free_system(&sys);
	return (0);
}
