/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize_lst.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woonshin <woonshin@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 05:32:56 by woonshin          #+#    #+#             */
/*   Updated: 2024/06/15 05:34:52 by woonshin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tokenize.h"


t_token	*token_lst_back(t_token *token_lst)
{
	while (token_lst->next != NULL)
		token_lst = token_lst->next;
	return (token_lst);
}

void add_token(t_token **token_lst, t_token *token)
{
	t_token	*back;

	if ((*token_lst) == 0)
	{
		*token_lst = token;
		return ;
	}
	back = token_lst_back(*token_lst);
	back->next = token;
}

t_token *new_token(char *line, int l, int r)
{
	t_token	*token;

	token = (t_token *)ft_calloc(1, sizeof(t_token));
	if (token == NULL)
		exit(0);
	token->str = ft_substr(line, l, r - l);
	token->type = get_token_type(token->str);
	return (token);
}