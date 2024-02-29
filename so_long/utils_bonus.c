/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woonshin <woonshin@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 11:58:50 by woonshin          #+#    #+#             */
/*   Updated: 2024/02/25 15:22:06 by woonshin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	new_2d_array(char ***arr, int width, int height)
{
	size_t	i;

	i = 0;
	*arr = (char **) ft_calloc(height + 1, sizeof(char *));
	if (*arr == NULL)
		return_error();
	while (i < (size_t) height)
	{
		*((*arr) + i) = (char *) ft_calloc(width + 1, sizeof(char));
		if (*((*arr) + i) == NULL)
			return_error();
		i++;
	}
}

void	return_error(void)
{
	ft_putstr_fd("Error\n", 1);
	exit(1);
}

void	return_ok(void)
{
	ft_putstr_fd("OK\n", 1);
	sleep(1);
	exit(0);
}

void	return_ko(void)
{
	ft_putstr_fd("KO\n", 1);
	sleep(1);
	exit(0);
}

int	is_frame(t_map_info *map_info, int x, int y)
{
	return (0 <= x && (size_t)x < map_info->width
		&& 0 <= y && (size_t)y < map_info->height);
}
