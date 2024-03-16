/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_validate_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woonshin <woonshin@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 21:38:02 by woonshin          #+#    #+#             */
/*   Updated: 2024/03/16 20:32:42 by woonshin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	is_validation(char *str);
int	duplicate_check(int n, char *arr[]);
int	int_range_check(int n, char *arr[]);
int	overflow_check(const char *str, char sign_bit);

int	input_validate(int n, char *arr[])
{
	int	i;

	i = 0;
	while (i < n)
	{
		if (is_validation(arr[i]) != 0)
			return (1);
		if (arr[i][0] == '\0')
			return (1);
		if (2 <= ft_strlen(arr[i]) && arr[i][0] == (char) '0')
			return (1);
		if (2 <= ft_strlen(arr[i])
			&& arr[i][0] == (char) '-' && arr[i][1] == (char) '0')
			return (1);
		if (2 <= ft_strlen(arr[i])
			&& arr[i][0] == (char) '+' && arr[i][1] == (char) '0')
			return (1);
		i++;
	}
	if (duplicate_check(n, arr) != 0 || int_range_check(n, arr) != 0)
		return (1);
	return (0);
}

int	is_validation(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-')
		i++;
	if (!ft_isdigit(str[i]))
		return (1);
	while (str[i] != 0)
	{
		if (!ft_isdigit(str[i]))
			return (1);
		i++;
	}
	return (0);
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
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	int_range_check(int n, char *arr[])
{
	int		i;
	char	sign_bit;
	int		overflow_result;

	sign_bit = 0;
	i = 0;
	while (i < n)
	{
		sign_bit = 0;
		if (arr[i][0] == '-')
			sign_bit = 1;
		if (sign_bit == 0)
			overflow_result = overflow_check(arr[i], sign_bit);
		else
			overflow_result = overflow_check(arr[i] + 1, sign_bit);
		if (overflow_result != 0)
			return (overflow_result);
		i++;
	}
	return (0);
}

int	overflow_check(const char *str, char sign_bit)
{
	size_t	len;

	len = ft_strlen(str);
	if (len < 10)
		return (0);
	else if (10 < len)
		return (1);
	if (sign_bit == 0 && ft_strncmp(str, "2147483647", 10) > 0)
		return (1);
	if (sign_bit == 1 && ft_strncmp(str, "2147483648", 10) > 0)
		return (-1);
	return (0);
}
