/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woonshin <woonshin@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 16:15:15 by woonshin          #+#    #+#             */
/*   Updated: 2024/09/08 14:28:50 by woonshin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error.h"

char	*get_error(int error_no)
{
	if (error_no == ARGS_ERR)
		return ("ARGS_ERROR");
	else if (error_no == MALLOC_ERR)
		return ("MALLOC_ERROR");
	else if (error_no == SEM_ERR)
		return ("SEM_ERR");
	else if (error_no == FORK_ERR)
		return ("FORK_ERR");
	else
		return ("ERROR");
}

void	err_return(int error_no)
{
	printf("%s\n", get_error(error_no));
	exit(error_no);
}
