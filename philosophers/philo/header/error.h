/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woonshin <woonshin@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 16:15:26 by woonshin          #+#    #+#             */
/*   Updated: 2024/09/09 13:32:13 by woonshin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H
# include <stdio.h>
# include <stdlib.h>

# define ERROR 1
# define ARGS_ERR 2
# define MALLOC_ERR 3
# define MUTEX_ERR 4

char	*get_error(int error_no);
int		err_return(int error_no);

#endif
