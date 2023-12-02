/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_load_formatter.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woonshin <woonshin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 23:14:34 by woonshin          #+#    #+#             */
/*   Updated: 2023/12/02 23:37:54 by woonshin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	(*get_formatter(char format))(char*)
{
	if (format == 'c')
		return print_char;
	// else if (format == 's')
		
	// else if (format == 'p')
		
	// else if (format == 'd' || format == 'i')
		
	// else if (format == 'u')
		
	// else if (format == 'x' || format == 'X')
		
	// else if (format == '%')
		
}