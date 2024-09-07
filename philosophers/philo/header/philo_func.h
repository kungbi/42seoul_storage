/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_func.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woonshin <woonshin@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 13:43:58 by woonshin          #+#    #+#             */
/*   Updated: 2024/09/07 16:37:53 by woonshin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_FUNC_H
# define PHILO_FUNC_H
# include <stdio.h>
# include <pthread.h>
# include "struct.h"
# include "libft.h"

# define D_FORK 0
# define D_EATING 1
# define D_SLEEPING 2
# define D_THINKING 3
# define D_DIED 4

int	check_philo(t_system *system);
int	ft_usleep(long long time, t_system *system);
int	philo_print(t_system *system, t_philo *philo, int status);
int	check_stop(t_system *system);
int stop_philo(t_system *system);

int	philo_fork(t_system *system, t_philo *philo);
int	philo_eating(t_system *system, t_philo *philo);
int	philo_sleeping(t_system *system, t_philo *philo);
int	philo_thinking(t_system *system, t_philo *philo);

#endif