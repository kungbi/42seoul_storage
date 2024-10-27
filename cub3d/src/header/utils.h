/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woonshin <woonshin@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 12:18:36 by woonshin          #+#    #+#             */
/*   Updated: 2024/10/12 15:07:58 by woonshin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H
# include "structs.h"

void	init_system(t_system *sys);
void	init_raycast(t_system *sys);

void	arr_map_int(int dst[3], char *src);
int		ft_arrlen(char **arr);
char	*newline_trim(char *str);
char	**strarr_join(char **dst, char *src);

void	free_components(t_components *components);
void	arr_2nd_free(char **arr);
void	free_components(t_components *components);
void	free_system(t_system *sys);
void	free_graphics(t_system *sys);

char	**visited_map(char **map);

#endif