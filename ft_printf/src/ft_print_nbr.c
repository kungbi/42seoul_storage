/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_nbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woonshin <woonshin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 17:08:34 by woonshin          #+#    #+#             */
/*   Updated: 2023/12/25 18:02:21 by woonshin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	get_len(int num);

int	ft_print_nbr(int num)
{
	int	length;

	ft_putnbr_fd(num, 1);
	length = get_len(num);
	if (0 < length)
		return (length);
	return (1);
}

int	get_len(int num)
{
	int		len;
	long	num_l;

	num_l = (long)num;
	if (num_l < 0)
		num_l *= -1;
	len = 0;
	while (0 < num_l)
	{
		num_l /= 10;
		len++;
	}
	if (num < 0)
		len++;
	return (len);
}
