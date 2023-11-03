/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woonshin <woonshin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 20:42:31 by woonshin          #+#    #+#             */
/*   Updated: 2023/11/03 15:59:42 by woonshin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*result;
	size_t	i;

	if (count == 0 || size == 0)
		return (malloc(0));
	if (!(count <= -1 / size))
		return (NULL);
	i = 0;
	result = (void *)malloc(size * count);
	if (result == NULL)
		return (NULL);
	ft_memset(result, 0, size * count);
	return (result);
}
