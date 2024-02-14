/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_nbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woonshin <woonshin@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 17:08:34 by woonshin          #+#    #+#             */
/*   Updated: 2024/02/14 12:53:22 by woonshin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(int n);
int	get_digit(int n);

int	ft_print_nbr(int num)
{
	int	length;

	if (ft_putnbr(num) < 0)
		return (-1);
	length = get_digit(num);
	if (num < 0)
		length++;
	if (0 < length)
		return (length);
	return (1);
}

int	ft_putnbr(int n)
{
	int		digit;
	long	num;
	char	result[33];

	num = n;
	if (n < 0)
	{
		num *= -1;
		if (ft_print_char('-') < 0)
			return (-1);
	}
	ft_memset(result, 0, 33);
	digit = get_digit(n);
	digit--;
	while (0 <= digit)
	{
		result[digit] = "0123456789"[num % 10];
		num /= 10;
		digit--;
	}
	if (ft_print_str(result) < 0)
		return (-1);
	return (1);
}

int	get_digit(int n)
{
	int	digit;

	digit = 1;
	while (n / 10 != 0)
	{
		n /= 10;
		digit++;
	}
	return (digit);
}
