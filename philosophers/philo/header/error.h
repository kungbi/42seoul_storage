/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woonshin <woonshin@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 16:15:26 by woonshin          #+#    #+#             */
/*   Updated: 2024/09/02 16:04:59 by woonshin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H
# include <stdio.h>
# include <stdlib.h>

# define ARGS_ERR 1
# define MALLOC_ERR 2
# define MUTEX_ERR 3

char	*get_error(int error_no);
void	err_return(int error_no);

#endif
