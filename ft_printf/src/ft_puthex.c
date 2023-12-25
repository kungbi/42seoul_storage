/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woonshin <woonshin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 11:45:48 by woonshin          #+#    #+#             */
/*   Updated: 2023/12/25 12:15:25 by woonshin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include "libft.h"

void	ft_puthex_long_long(long long num)
{
	char	*hex;
	char	result[16];
	int		i;

	hex = "0123456789abcdef";
	ft_memset(result, '0', 16);
	i = 15;
	while (0 < num)
	{
		result[i] = hex[num % 16];
		num /= 16;
		i--;
	}
	i++;
	while (i < 16)
	{
		write(1, &result[i], 1);
		i++;
	}
}

void	ft_puthex_unsigned_int(unsigned int num, int upper)
{
	char	*hex;
	char	*hex_upper;
	char	result[16];
	int		i;

	hex = "0123456789abcdef";
	hex_upper = "0123456789ABCDEF";
	ft_memset(result, '0', 16);
	i = 15;
	while (0 < num)
	{
		if (upper == 1)
			result[i] = hex_upper[num % 16];
		else
			result[i] = hex[num % 16];
		num /= 16;
		i--;
	}
	i++;
	while (i < 16)
	{
		write(1, &result[i], 1);
		i++;
	}
}
