/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woonshin <woonshin@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 21:10:03 by woonshin          #+#    #+#             */
/*   Updated: 2024/10/10 15:25:39 by woonshin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error.h"

void	error_exit(int error)
{
	if (error == PARSE_ERROR)
		ft_putstr_fd("PARSE_ERROR\n", 2);
	else if (error == ARG_ERROR)
		ft_putstr_fd("ARG_ERROR\n", 2);
	else if (error == MALLOC_ERROR)
		ft_putstr_fd("MALLOC_ERROR\n", 2);
	else if (error == GAME_ERROR)
		ft_putstr_fd("GAME_ERROR\n", 2);
	else
		ft_putstr_fd("ERROR\n", 2);
	if (1 <= error)
		exit(error);
	exit(1);
}
