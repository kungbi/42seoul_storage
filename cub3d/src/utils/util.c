/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woonshin <woonshin@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 12:18:12 by woonshin          #+#    #+#             */
/*   Updated: 2024/10/12 19:12:26 by woonshin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "error.h"

void	arr_2nd_free(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		if (arr[i] != NULL)
			free(arr[i]);
		i++;
	}
	if (arr != NULL)
		free(arr);
}

void	arr_map_int(int dst[3], char *src)
{
	int		i;
	char	**tokens;

	tokens = ft_split(src, ',');
	if (!tokens)
		error_exit(ERROR);
	if (ft_arrlen(tokens) != 3)
		error_exit(PARSE_ERROR);
	i = 0;
	while (i < 3)
	{
		dst[i] = ft_atoi(tokens[i]);
		i++;
	}
	arr_2nd_free(tokens);
}

int	ft_arrlen(char **arr)
{
	int	count;

	count = 0;
	while (arr[count])
		count++;
	return (count);
}

char	*newline_trim(char *str)
{
	int	i;

	i = ft_strlen(str) - 1;
	while (0 <= i)
	{
		if (str[i] == '\n')
			str[i] = '\0';
		i--;
	}
	return (str);
}

char	**strarr_join(char **dst, char *src)
{
	int		i;
	int		len;
	char	**new;

	if (!dst)
	{
		dst = (char **)malloc(sizeof(char *));
		dst[0] = NULL;
	}
	len = ft_arrlen(dst);
	new = (char **)malloc(sizeof(char *) * (len + 2));
	if (!new)
		error_exit(MALLOC_ERROR);
	i = 0;
	while (i < len)
	{
		new[i] = dst[i];
		i++;
	}
	new[i] = src;
	new[i + 1] = NULL;
	if (dst)
		free(dst);
	return (new);
}
