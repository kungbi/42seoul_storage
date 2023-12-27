/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned_int.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woonshin <woonshin@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 12:00:59 by woonshin          #+#    #+#             */
/*   Updated: 2023/12/27 09:07:16 by woonshin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_put_unsigned_int(unsigned int num);

int	ft_print_unsigned_int(unsigned int num)
{
	int	len;

	len = ft_put_unsigned_int(num);
	if (len < 0)
		return (-1);
	if (num == 0)
	{
		if (write(1, "0", 1) < 0)
			return (-1);
		len++;
	}
	return (len);
}

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
	len = 9 - i;
	i++;
	while (i < 10)
	{
		if (write(1, &result[i], 1) < 0)
			return (-1);
		i++;
	}
	return (len);
}
