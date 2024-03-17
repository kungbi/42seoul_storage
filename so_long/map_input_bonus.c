/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_input_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woonshin <woonshin@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 04:27:29 by woonshin          #+#    #+#             */
/*   Updated: 2024/03/17 18:35:16 by woonshin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	map_input_size(t_map_info *map_info, char *filename);
void	map_input_getline(t_map_info *map_info, char *filename);
void	remove_nl(char *str);

void	map_input(t_map_info *map_info, char *filename)
{
	map_input_size(map_info, filename);
	new_2d_array(&map_info->map, map_info->width, map_info->height);
	map_input_getline(map_info, filename);
}

void	map_input_size(t_map_info *map_info, char *filename)
{
	int		fd;
	char	*str;
	size_t	len;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return_error();
	str = get_next_line(fd);
	while (str != NULL)
	{
		remove_nl(str);
		len = ft_strlen(str);
		if (map_info->width == (size_t)(-1))
			map_info->width = len;
		else if (map_info->width != len)
			return_error();
		free(str);
		str = get_next_line(fd);
		map_info->height++;
	}
	close(fd);
	if (map_info->width == 0 || map_info->height == 0)
		return_error();
}

void	map_input_getline(t_map_info *map_info, char *filename)
{
	int		fd;
	char	*str;
	size_t	i;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return_error();
	i = 0;
	str = get_next_line(fd);
	while (str != NULL)
	{
		ft_strlcpy((char *)map_info->map[i], str, map_info->width + 1);
		free(str);
		str = get_next_line(fd);
		i++;
	}
	close(fd);
}

void	remove_nl(char *str)
{
	int	len;

	len = ft_strlen(str);
	if (len == 0)
		return ;
	if (str[len - 1] == '\n')
		str[len - 1] = '\0';
}
