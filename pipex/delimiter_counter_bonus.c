/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delimiter_counter_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woonshin <woonshin@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 16:15:03 by woonshin          #+#    #+#             */
/*   Updated: 2024/06/06 16:15:53 by woonshin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	delimiter_counter(char *delimiter, size_t *cnt, char c)
{
	if (*delimiter == '\0')
	{
		*delimiter = c;
		*cnt = 1;
		return ;
	}
	else if (*delimiter == c)
		*cnt = *cnt + 1;
	if (*cnt % 2 == 0)
		*delimiter = '\0';
}
