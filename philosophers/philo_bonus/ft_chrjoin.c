/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_chrjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woonshin <woonshin@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 13:30:54 by woonshin          #+#    #+#             */
/*   Updated: 2024/09/08 13:58:49 by woonshin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;
	char	*char_dst;
	char	*char_src;

	if (dst == NULL && src == NULL)
		return (NULL);
	if (src == NULL && n == 0)
		return (dst);
	char_dst = (char *)dst;
	char_src = (char *)src;
	i = 0;
	while (i < n)
	{
		char_dst[i] = char_src[i];
		i++;
	}
	return (dst);
}

char	*ft_chrjoin(char const *s1, char const s2)
{
	size_t	s1_len;
	size_t	result_len;
	char	*result;

	if ((s1 == NULL && s2 == 0))
		return (NULL);
	s1_len = ft_strlen(s1);
	result_len = s1_len + 1;
	result = (char *)ft_calloc(result_len + 1, sizeof(char));
	if (result == NULL)
		return (NULL);
	ft_memcpy(result, s1, s1_len);
	result[s1_len] = s2;
	return (result);
}
