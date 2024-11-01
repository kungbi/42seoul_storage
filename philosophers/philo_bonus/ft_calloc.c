/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woonshin <woonshin@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 20:42:31 by woonshin          #+#    #+#             */
/*   Updated: 2024/09/08 13:57:07 by woonshin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*result;

	if (count == 0 || size == 0)
		return (malloc(0));
	if (!(count <= -1 / size))
		return (NULL);
	result = (void *)malloc(size * count);
	if (result == NULL)
		return (NULL);
	memset(result, 0, size * count);
	return (result);
}
