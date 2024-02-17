/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_input.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woonshin <woonshin@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 04:27:29 by woonshin          #+#    #+#             */
/*   Updated: 2024/02/17 10:42:39 by woonshin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	map_resize(t_map_info *map_info);
void	map_input_size(t_map_info *map_info, char *filename);
void	map_input_getline(t_map_info *map_info, char *filename);
void	remove_nl(char *str);

void	map_input(t_map_info *map_info, char *filename)
{
	map_input_size(map_info, filename);
	map_resize(map_info);
	map_input_getline(map_info, filename);
}

void	map_resize(t_map_info *map_info)
{
	size_t	i;

	map_info->map = (char **)ft_calloc(map_info->height + 1, sizeof(char *));
	if (map_info->map == NULL)
		return_error();
	i = 0;
	while (i < map_info->height)
	{
		map_info->map[i] = (char *)ft_calloc(map_info->width + 1, sizeof(char));
		if (map_info->map[i] == NULL)
			return_error();
		i++;
	}
}

void	map_input_size(t_map_info *map_info, char *filename)
{
	int		fd;
	char	*str;
	size_t	len;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return_error();
	map_info->width = -1;
	map_info->height = 0;
	str = get_next_line(fd);
	while (str != NULL)
	{
		remove_nl(str);
		len = ft_strlen(str);
		if (map_info->width == -1)
			map_info->width = len;
		else if (map_info->width != len)
			return_error();
		free(str);
		str = get_next_line(fd);
		map_info->height++;
	}
	if (map_info->width == map_info->height
		|| map_info->width == 0 || map_info->height == 0)
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
