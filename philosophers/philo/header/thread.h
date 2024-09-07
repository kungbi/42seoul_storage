/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woonshin <woonshin@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 13:49:18 by woonshin          #+#    #+#             */
/*   Updated: 2024/09/07 12:49:42 by woonshin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef THREAD_H
# define THREAD_H
# include "struct.h"
# include "error.h"
# include "free.h"
# include "philo_func.h"

void	thread_func(void *data);
void	monitoring(t_system *system);
void	thread_start(t_system *system);

#endif