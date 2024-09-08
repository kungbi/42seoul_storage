/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_func.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woonshin <woonshin@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 13:43:58 by woonshin          #+#    #+#             */
/*   Updated: 2024/09/08 21:09:42 by woonshin         ###   ########.fr       */
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

int	ft_usleep(long long time, t_philo *philo);
int	philo_print(t_system *system, t_philo *philo, int status);
int	check_stop(t_philo *philo);
int	stop_philo(t_philo *philo);

int	philo_fork(t_system *system, t_philo *philo);
int	philo_eating(t_system *system, t_philo *philo);
int	philo_sleeping(t_system *system, t_philo *philo);
int	philo_thinking(t_system *system, t_philo *philo);

void	ft_sem_open(sem_t **sem, char *name, int num, int value);

#endif