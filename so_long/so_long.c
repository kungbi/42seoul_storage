/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woonshin <woonshin@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 01:17:14 by woonshin          #+#    #+#             */
/*   Updated: 2024/02/17 10:40:38 by woonshin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "so_long.h"

int	main(int argc, char *argv[])
{
	t_map_info	map_info;

	if (argc != 2)
		return_error();
	if (ft_strncmp(&argv[1][ft_strlen(argv[1]) - 4], ".ber", 4) != 0)
		return_error();
	map_info_init(&map_info);
	map_input(&map_info, argv[1]);
	map_check(&map_info);
}
