/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_split.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woonshin <woonshin@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 22:44:56 by woonshin          #+#    #+#             */
/*   Updated: 2024/03/02 09:59:32 by woonshin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	get_word_count(char const *s);
int	free_array(char **words, int x);
int	split_word(char const *s, char **words);
int	split_core(const char *s, char **words, int start, int i);

char	**command_split(char const *s)
{
	size_t	word_count;
	char	**result;

	if (s == NULL)
		return (NULL);
	word_count = get_word_count(s);
	result = (char **)ft_calloc((word_count + 1), sizeof(char *));
	if (result == NULL)
		return (NULL);
	if (split_word(s, result) != 0)
	{
		free(result);
		return (NULL);
	}
	return (result);
}

int	get_word_count(char const *s)
{
	size_t	i;
	size_t	word_count;
	size_t	j;

	i = 0;
	j = 0;
	word_count = 0;
	if (s[0] == '\0')
		return (0);
	else if (s[0] != ' ')
		word_count++;
	while (s[i] != '\0')
	{
		if (s[i] == '\'')
			j++;
		if (s[i] == ' ' && s[i + 1] != ' ' && s[i + 1] != '\0' && j % 2 == 0)
			word_count++;
		i++;
	}
	return (word_count);
}

int	split_word(char const *s, char **words)
{
	size_t	start;
	size_t	i;
	size_t	j;
	size_t	x;

	i = 0;
	j = 0;
	x = 0;
	start = 0;
	while (s[i] != '\0')
	{
		if (s[i] == '\'')
			j++;
		if (j % 2 == 1)
		{
			i++;
			continue ;
		}
		if (s[i] == ' ' && s[i + 1] != ' ')
			start = i + 1;
		if (split_core(s, &words[x], start, i))
			x++;
		i++;
	}
	return (0);
}

int	split_core(const char *s, char **words, int start, int i)
{
	if (s[i] != ' ' && (s[i + 1] == ' ' || s[i + 1] == '\0'))
	{
		if (s[start] == '\'')
			*words = ft_substr(s, start + 1, (i + 1) - start - 2);
		else
			*words = ft_substr(s, start, (i + 1) - start);
		if (*words == NULL)
			return_error(NULL, 1);
		return (1);
	}
	return (0);
}

int	free_array(char **words, int x)
{
	while (0 <= x)
	{
		free(words[x]);
		x--;
	}
	return (1);
}
