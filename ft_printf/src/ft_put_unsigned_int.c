/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_unsigned_int.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woonshin <woonshin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 12:00:59 by woonshin          #+#    #+#             */
/*   Updated: 2023/12/25 12:48:34 by woonshin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_put_unsigned_int(unsigned int num)
{
	char	*dec;
	char	result[10];
	int		i;
	int		len;

	dec = "0123456789";
	i = 9;
	while (0 < num)
	{
		result[i] = dec[num % 10];
		num /= 10;
		i--;
	}
	i++;
	len = 10 - i;
	while (i < 10)
	{
		write(1, &result[i], 1);
		i++;
	}
	return (len);
}
