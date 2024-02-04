/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_validate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woonshin <woonshin@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 21:38:02 by woonshin          #+#    #+#             */
/*   Updated: 2024/02/04 23:56:57 by woonshin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_validation(char *str);
int	duplicate_check(int n, char *arr[]);

int	input_validate(int n, char *arr[])
{
	int	i;

	if (n == 0)
		return (0);
	i = 0;
	while (i < n)
	{
		if (is_validation(arr[i]) == 0)
			return (0);
		i++;
	}
	if (duplicate_check(n, arr) == 0)
		return (0);
	return (1);
}

int	is_validation(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-')
		i++;
	if (!ft_isdigit(str[i]))
		return (0);
	while (str[i] != 0)
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

int	duplicate_check(int n, char *arr[])
{
	int	i;
	int	j;
	int	a_len;
	int	b_len;

	i = 0;
	while (i < n)
	{
		a_len = ft_strlen(arr[i]);
		j = 0;
		while (j < n)
		{
			b_len = ft_strlen(arr[j]);
			if (i != j
				&& a_len == b_len && ft_strncmp(arr[i], arr[j], a_len) == 0)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
