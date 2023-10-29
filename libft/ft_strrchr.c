/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woonshin <woonshin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 12:39:28 by woonshin          #+#    #+#             */
/*   Updated: 2023/10/07 15:41:08 by woonshin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	s_len;
	size_t	i;

	s_len = ft_strlen(s);
	i = s_len;
	while (0 <= i)
	{
		if (s[i] == (char)c)
			break ;
		if (i == 0)
			return (0);
		i--;
	}
	return ((char *)s + i);
}
