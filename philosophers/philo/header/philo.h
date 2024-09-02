/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woonshin <woonshin@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 14:02:31 by woonshin          #+#    #+#             */
/*   Updated: 2024/09/01 17:25:43 by woonshin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <stdio.h>
# include <pthread.h>
# include "error.h"
# include "libft.h"
# include "struct.h"
# include "free.h"
# include "time.h"

void	args_init(int ac, char **av, t_args *args);
void	system_init(t_system *system);

#endif
