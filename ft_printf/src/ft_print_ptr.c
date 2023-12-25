/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woonshin <woonshin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 10:59:41 by woonshin          #+#    #+#             */
/*   Updated: 2023/12/25 17:31:12 by woonshin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_ptr(long long ptr)
{
	int	length;

	length = 2;
	write(1, "0x", 2);
	if (ptr == (long long)0x8000000000000000)
	{
		write(1, "8000000000000000", 16);
		length += 16;
	}
	else if (ptr == 0)
	{
		write(1, "0", 1);
		length += 1;
	}
	else
		length += ft_print_hex_long_long(ptr);
	return (length);
}
