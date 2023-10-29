/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woonshin <woonshin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 20:42:31 by woonshin          #+#    #+#             */
/*   Updated: 2023/10/29 15:00:41 by woonshin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*result;
	size_t	i;

	result = (void *)malloc(size * count);
	i = 0;
	if (result == NULL)
		return (NULL);
	ft_memset(result, 0, size * count);
	return (result);
}
