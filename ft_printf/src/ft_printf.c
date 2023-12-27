/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woonshin <woonshin@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 00:35:02 by woonshin          #+#    #+#             */
/*   Updated: 2023/12/27 09:21:41 by woonshin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	formmater(const char *str, va_list *ap);

int	ft_printf(const char *str, ...)
{
	va_list	ap;
	int		length;
	int		write_result;

	length = 0;
	va_start(ap, str);
	while (*str)
	{
		if (*str == '%')
		{
			str++;
			write_result = formmater(str, &ap);
		}
		else
			write_result = write(1, str, 1);
		if (write_result < 0)
			return (-1);
		length += write_result;
		str++;
	}
	va_end(ap);
	return (length);
}

int	formmater(const char *str, va_list *ap)
{
	if (*str == '%')
		return (ft_print_char('%'));
	else if (*str == 'c')
		return (ft_print_char(va_arg(*ap, int)));
	else if (*str == 's')
		return (ft_print_str(va_arg(*ap, char *)));
	else if (*str == 'p')
		return (ft_print_ptr(va_arg(*ap, long long)));
	else if (*str == 'd')
		return (ft_print_nbr(va_arg(*ap, int)));
	else if (*str == 'i')
		return (ft_print_nbr(va_arg(*ap, int)));
	else if (*str == 'x')
		return (ft_print_hex_unsigned_int(va_arg(*ap, unsigned int), 0));
	else if (*str == 'X')
		return (ft_print_hex_unsigned_int(va_arg(*ap, unsigned int), 1));
	else if (*str == 'u')
		return (ft_print_unsigned_int(va_arg(*ap, unsigned int)));
	return (1);
}
