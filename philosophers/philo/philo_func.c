/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_func.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woonshin <woonshin@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 13:43:50 by woonshin          #+#    #+#             */
/*   Updated: 2024/09/05 13:46:58 by woonshin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_func.h"

int	philo_eating(t_system *system, t_philo *philo)
{
	if (system->stop_flag)
		return (1);
	pthread_mutex_lock(philo->left_fork);
	philo_print(system, philo, D_FORK);
	pthread_mutex_lock(philo->right_fork);
	philo_print(system, philo, D_FORK);
	pthread_mutex_lock(&philo->eat_mutex);
	philo_print(system, philo, D_EATING);
	philo->last_eat = get_time();
	philo->eat_count++;
	ft_usleep(system->args.eat_time, system);
	pthread_mutex_unlock(&philo->eat_mutex);
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
	return (0);
}

int	philo_sleeping(t_system *system, t_philo *philo)
{
	if (system->stop_flag)
		return (1);
	philo_print(system, philo, D_SLEEPING);
	ft_usleep(system->args.sleep_time, system);
	return (0);
}

int	philo_thinking(t_system *system, t_philo *philo)
{
	if (system->stop_flag)
		return (1);
	philo_print(system, philo, D_THINKING);
	return (0);
}
