/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woonshin <woonshin@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 21:10:12 by woonshin          #+#    #+#             */
/*   Updated: 2024/10/12 15:56:29 by woonshin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H
# include <errno.h>
# include <stdlib.h>
# include "libft.h"

# define ERROR 1
# define PARSE_ERROR 2
# define ARG_ERROR 3
# define MALLOC_ERROR 4
# define GAME_ERROR 5

void	error_exit(int error);

#endif