/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woonshin <woonshin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 11:45:48 by woonshin          #+#    #+#             */
/*   Updated: 2023/12/25 18:03:29 by woonshin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include "libft.h"

int	ft_put_hex_unsigned_int(unsigned int num, int upper);
int	ft_put_hex_long_long(unsigned long num);

int	ft_print_hex_long_long(long long num)
{
	int		len;

	len = ft_put_hex_long_long((unsigned long)num);
	if (num == 0)
	{
		write(1, "0", 1);
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
		write(1, &result[i], 1);
		i++;
	}
	return (len);
}

int	ft_print_hex_unsigned_int(unsigned int num, int upper)
{
	int		len;

	len = ft_put_hex_unsigned_int(num, upper);
	if (num == 0)
	{
		write(1, "0", 1);
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
		write(1, &result[i], 1);
		i++;
	}
	return (len);
}
