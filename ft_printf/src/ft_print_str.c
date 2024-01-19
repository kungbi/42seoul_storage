/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woonshin <woonshin@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 23:14:30 by woonshin          #+#    #+#             */
/*   Updated: 2023/12/27 09:13:03 by woonshin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_str(char *s)
{
	int	len;

	if (s == NULL)
	{
		if (write(1, "(null)", 6) < 0)
			return (-1);
		return (6);
	}
	len = 0;
	while (s[len] != '\0')
	{
		if (write(1, &s[len], 1) < 0)
			return (-1);
		len++;
	}
	return (len);
}
