/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woonshin <woonshin@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 13:16:58 by woonshin          #+#    #+#             */
/*   Updated: 2024/10/12 15:55:27 by woonshin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "libft.h"
#include <stdlib.h>
#include "error.h"

char	**visited_map(char **map)
{
	char	**visited;
	int		i;

	visited = (char **)malloc(sizeof(char *) * (ft_arrlen(map) + 1));
	if (!visited)
		error_exit(MALLOC_ERROR);
	i = 0;
	while (i < ft_arrlen(map))
	{
		visited[i] = (char *)malloc(ft_strlen(map[i]) + 1);
		if (visited[i] == NULL)
			error_exit(MALLOC_ERROR);
		i++;
	}
	visited[i] = NULL;
	return (visited);
}
