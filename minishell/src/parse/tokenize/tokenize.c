/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woonshin <woonshin@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 13:19:17 by woonshin          #+#    #+#             */
/*   Updated: 2024/06/15 06:37:19 by woonshin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tokenize.h"


void	tokenize(t_token **token_lst, char *line)
{
	int left = 0, right = 0;
	int in_single_quote = 0, in_double_quote = 0;
	t_token	*token;

	while (right < (int)ft_strlen(line))
	{
		while (line[right] != '\0' && is_delimiter(line[right]))
			right++;
		left = right;

		while (line[right] != '\0' && 
			   (!is_delimiter(line[right]) || in_single_quote || in_double_quote))
		{
			if (line[right] == '\'' && !in_double_quote)
				in_single_quote = !in_single_quote;
			else if (line[right] == '"' && !in_single_quote)
				in_double_quote = !in_double_quote;
			right++;
		}
		if (right > left)
		{
			token = new_token(line, left, right);
			if (tokenize_expend(token_lst, token) == 0)
				add_token(token_lst, token);
		}
	}
	if (in_single_quote || in_double_quote)
		exit(0);
}
