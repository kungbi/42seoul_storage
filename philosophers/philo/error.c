/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woonshin <woonshin@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 16:15:15 by woonshin          #+#    #+#             */
/*   Updated: 2024/09/02 16:05:09 by woonshin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error.h"

char	*get_error(int error_no)
{
	if (error_no == ARGS_ERR)
		return ("ARGS_ERROR");
	else if (error_no == MALLOC_ERR)
		return ("MALLOC_ERROR");
	else if (error_no == MUTEX_ERR)
		return ("MUTEX_ERROR");
	else
		return ("ERROR");
}

void	err_return(int error_no)
{
	printf("%s\n", get_error(error_no));
	exit(error_no);
}
