/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woonshin <woonshin@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 11:45:48 by woonshin          #+#    #+#             */
/*   Updated: 2023/12/27 09:15:13 by woonshin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_put_hex_unsigned_int(unsigned int num, int upper);
int		ft_put_hex_long_long(unsigned long num);

int	ft_print_hex_long_long(long long num)
{
	int	len;

	len = ft_put_hex_long_long((unsigned long)num);
	if (len < 0)
		return (-1);
	if (num == 0)
	{
		if (write(1, "0", 1) < 0)
			return (-1);
		len++;
	}
	return (len);
}

int	ft_put_hex_long_long(unsigned long num)
{
	char	*hex;
	char	result[16];
	int		i;
	int		len;

	hex = "0123456789abcdef";
	ft_memset(result, '0', 16);
	i = 15;
	while (0 < num)
	{
		result[i] = hex[num % 16];
		num /= 16;
		i--;
	}
	len = 15 - i;
	i++;
	while (i < 16)
	{
		if (write(1, &result[i], 1) < 0)
			return (-1);
		i++;
	}
	return (len);
}

int	ft_print_hex_unsigned_int(unsigned int num, int upper)
{
	int		len;

	len = ft_put_hex_unsigned_int(num, upper);
	if (len < 0)
		return (-1);
	if (num == 0)
	{
		if (write(1, "0", 1) < 0)
			return (-1);
		len++;
	}
	return (len);
}

int	ft_put_hex_unsigned_int(unsigned int num, int upper)
{
	char	*hex;
	char	result[16];
	int		i;
	int		len;

	hex = "0123456789abcdef";
	ft_memset(result, '0', 16);
	i = 15;
	while (0 < num)
	{
		result[i] = hex[num % 16];
		num /= 16;
		if (upper == 1 && 'a' <= result[i] && result[i] <= 'f')
			result[i] = result[i] - 'a' + 'A';
		i--;
	}
	len = 15 - i;
	i++;
	while (i < 16)
	{
		if (write(1, &result[i], 1) < 0)
			return (-1);
		i++;
	}
	return (len);
}
