/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woonshin <woonshin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 00:35:02 by woonshin          #+#    #+#             */
/*   Updated: 2023/12/25 18:03:10 by woonshin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	formmater(const char *str, va_list *ap);
int	ft_print_char(int c);
int	ft_print_str(char *s);

int	ft_printf(const char *str, ...)
{
	va_list	ap;
	int		length;

	length = 0;
	va_start(ap, str);
	while (*str)
	{
		if (*str == '%')
		{
			str++;
			length += formmater(str, &ap);
		}
		else
		{	
			length += 1;
			write(1, str, 1);
		}
		str++;
	}
	va_end(ap);
	return (length);
}

int	ft_print_char(int c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_print_str(char *s)
{
	int	len;

	if (s == NULL)
	{
		write(1, "(null)", 6);
		return (6);
	}
	len = 0;
	while (s[len] != '\0')
	{
		write(1, &s[len], 1);
		len++;
	}
	return (len);
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
	return (0);
}
