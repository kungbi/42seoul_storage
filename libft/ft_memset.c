/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woonshin <woonshin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 16:57:58 by woonshin          #+#    #+#             */
/*   Updated: 2023/10/29 14:54:16 by woonshin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	char			c_uc;
	unsigned char	*b_uc;

	i = 0;
	b_uc = (unsigned char *)b;
	c_uc = (unsigned char)c;
	while (i < len)
	{
		b_uc[i] = c;
		i++;
	}
	return (b);
}
