/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woonshin <woonshin@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 13:19:17 by woonshin          #+#    #+#             */
/*   Updated: 2024/06/15 05:42:24 by woonshin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tokenize.h"


void tokenize(t_token **token_lst, char *line)
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
		printf("%d %d\n", left, right);
		if (right > left)
		{
			if (is_quotation_str(line, left, right))
				token = new_token(line, left + 1, right - 1);
			else
				token = new_token(line, left, right);
			// 여기에서 dollar 처리. token_lst_back 이 HERE이 아니면.
			add_token(token_lst, token);
		}
	}
}
