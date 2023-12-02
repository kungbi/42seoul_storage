/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woonshin <woonshin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 00:35:02 by woonshin          #+#    #+#             */
/*   Updated: 2023/12/02 23:40:14 by woonshin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *str, ...)
{
	va_list	ap;
	void	(*formatter)(void*);
	void	*data;

	va_start(ap, str);
	while (*str)
	{
		if (*str == '%')
		{
			data = va_arg(ap, char *);
			formatter(data);
		}
		str++;
	}
	va_end(ap);
	return (0);
}
