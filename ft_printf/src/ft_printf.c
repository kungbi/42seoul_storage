/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woonshin <woonshin@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 00:35:02 by woonshin          #+#    #+#             */
/*   Updated: 2023/12/26 00:48:27 by woonshin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	formmater(const char *str, va_list *ap);

int	ft_printf(const char *str, ...)
{
	va_list	ap;
	int		length;
	int		formmater_result;

	length = 0;
	va_start(ap, str);
	while (*str)
	{
		if (*str == '%')
		{
			str++;
			formmater_result = formmater(str, &ap);
			if (formmater_result < 0)
				return (-1);
			length += formmater_result;
		}
		else
		{
			length += 1;
			if (write(1, str, 1) < 0)
				return (-1);
		}
		str++;
	}
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
