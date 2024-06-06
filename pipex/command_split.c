/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_split.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woonshin <woonshin@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 22:44:56 by woonshin          #+#    #+#             */
/*   Updated: 2024/06/06 16:15:00 by woonshin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int		get_word_count(char const *s);
int		split_word(char const *s, char **words);
int		split_core(const char *s, char **words, int start, int i);
void	delimiter_counter(char *delimiter, size_t *cnt, char c);
void	remove_backslash(char **words);

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
	remove_backslash(result);
	return (result);
}

void	remove_backslash(char **words)
{
	size_t	i;
	size_t	j;
	size_t	cnt;

	cnt = 0;
	i = 0;
	while (words[i] != NULL)
	{
		j = 0;
		while (words[i][j] != '\0')
		{
			while (words[i][j + cnt] == '\\')
				cnt++;
			words[i][j] = words[i][j + cnt];
			if (words[i][j] == '\0')
				break ;
			j++;
		}
		i++;
	}
}

int	get_word_count(char const *s)
{
	size_t	i;
	size_t	word_count;
	size_t	j;
	char	delimiter;

	i = 0;
	j = 0;
	word_count = 0;
	delimiter = 0;
	if (s[0] == '\0')
		return (0);
	else if (s[0] != ' ')
		word_count++;
	while (s[i] != '\0')
	{
		if ((s[i] == '\'' || s[i] == '\"') && s[i - 1] != '\\')
			delimiter_counter(&delimiter, &j, s[i]);
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
	char	delimiter;

	i = 0;
	j = 0;
	x = 0;
	start = 0;
	delimiter = 0;
	while (s[i] != '\0')
	{
		if ((s[i] == '\'' || s[i] == '\"') && s[i - 1] != '\\')
			delimiter_counter(&delimiter, &j, s[i]);
		if (j % 2 == 0)
		{
			if (s[i] == ' ' && s[i + 1] != ' ')
				start = i + 1;
			if (split_core(s, &words[x], start, i))
				x++;
		}
		i++;
	}
	return (0);
}

int	split_core(const char *s, char **words, int start, int i)
{
	if (s[i] != ' ' && (s[i + 1] == ' ' || s[i + 1] == '\0'))
	{
		if (s[start] == '\'' || s[start] == '\"')
			*words = ft_substr(s, start + 1, (i + 1) - start - 2);
		else
			*words = ft_substr(s, start, (i + 1) - start);
		if (*words == NULL)
			return_error(NULL, 1);
		return (1);
	}
	return (0);
}
