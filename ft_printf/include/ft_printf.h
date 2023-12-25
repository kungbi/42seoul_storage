/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woonshin <woonshin@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 00:35:28 by woonshin          #+#    #+#             */
/*   Updated: 2023/12/26 00:17:18 by woonshin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

int		ft_printf(const char *str, ...);
int		ft_print_ptr(long long ptr);
int		ft_print_hex_long_long(long long ptr);
int		ft_print_hex_unsigned_int(unsigned int num, int upper);
int		ft_print_unsigned_int(unsigned int num);
int		ft_print_nbr(int num);
int		ft_print_char(int c);
int		ft_print_str(char *s);
void	*ft_memset(void *b, int c, size_t len);

#endif
