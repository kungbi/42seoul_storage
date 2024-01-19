/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woonshin <woonshin@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 10:59:41 by woonshin          #+#    #+#             */
/*   Updated: 2023/12/26 00:44:23 by woonshin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_put_ptr(long long ptr);

int	ft_print_ptr(long long ptr)
{
	int	length;
	int	print_hex_result;

	length = 2;
	if (write(1, "0x", 2) < 0)
		return (-1);
	if (ptr == (long long)0x8000000000000000)
	{
		if (write(1, "8000000000000000", 16) < 0)
			return (-1);
		return (18);
	}
	print_hex_result = ft_put_ptr(ptr);
	if (print_hex_result < 0)
		return (-1);
	return (length + print_hex_result);
}

int	ft_put_ptr(long long ptr)
{
	int	result;

	if (ptr == 0)
	{
		if (write(1, "0", 1) < 0)
			return (-1);
		return (1);
	}
	result = ft_print_hex_long_long(ptr);
	if (result < 0)
		return (-1);
	return (result);
}
