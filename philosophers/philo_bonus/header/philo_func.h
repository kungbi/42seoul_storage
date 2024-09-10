/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_func.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woonshin <woonshin@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 13:43:58 by woonshin          #+#    #+#             */
/*   Updated: 2024/09/10 17:40:34 by woonshin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_FUNC_H
# define PHILO_FUNC_H
# include <stdio.h>
# include <pthread.h>
# include <unistd.h>
# include <signal.h>
# include "struct.h"
# include "libft.h"
# include "error.h"

# define D_FORK 0
# define D_EATING 1
# define D_SLEEPING 2
# define D_THINKING 3
# define D_DIED 4

int		philo_print(t_system *system, t_philo *philo, int status);
void	ft_usleep(int sleep_time);
void	stop_processes(t_system *system);

int		philo_fork(t_system *system, t_philo *philo);
int		philo_eating(t_system *system, t_philo *philo);
int		philo_sleeping(t_system *system, t_philo *philo);
int		philo_thinking(t_system *system, t_philo *philo);

void	ft_sem_open(sem_t **sem, char *name, int num, int value);

void	process_monitoring(t_system *system);
void	fulll_monitoring(void *args);
void	died_monitoring(void *args);

#endif