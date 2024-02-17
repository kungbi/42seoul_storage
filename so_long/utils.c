/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woonshin <woonshin@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 11:58:50 by woonshin          #+#    #+#             */
/*   Updated: 2024/02/17 13:52:31 by woonshin         ###   ########.fr       */
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
	while (i < height)
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
