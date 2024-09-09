/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woonshin <woonshin@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 13:49:18 by woonshin          #+#    #+#             */
/*   Updated: 2024/09/09 14:48:02 by woonshin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef THREAD_H
# define THREAD_H
# include "struct.h"
# include "error.h"
# include "free.h"
# include "philo_func.h"

void	process_func(t_system *system, int id);
void	process_start(t_system *system);
void 	stop_processes(t_system *system);
void	fulll_monitoring(void *args);
void	process_monitoring(t_system *system);

#endif