/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_func.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woonshin <woonshin@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 13:43:50 by woonshin          #+#    #+#             */
/*   Updated: 2024/09/07 13:20:43 by woonshin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_func.h"

int	philo_eating(t_system *system, t_philo *philo)
{
	if (check_stop(system))
		return (1);
	pthread_mutex_lock(philo->left_fork);
	philo_print(system, philo, D_FORK);
	pthread_mutex_lock(philo->right_fork);
	philo_print(system, philo, D_FORK);
	
	pthread_mutex_lock(&philo->eat_mutex);
	philo->last_eat = get_time();
	philo->eat_count++;
	pthread_mutex_unlock(&philo->eat_mutex);
	
	philo_print(system, philo, D_EATING);
	ft_usleep(system->args.eat_time, system);

	
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);

	if (philo->eat_count == system->args.eat_num)
	{
		pthread_mutex_lock(&system->full_mutex);
		system->full_count++;
		pthread_mutex_unlock(&system->full_mutex);
	}
	return (0);
}

int	philo_sleeping(t_system *system, t_philo *philo)
{
	if (check_stop(system))
		return (1);
	philo_print(system, philo, D_SLEEPING);
	ft_usleep(system->args.sleep_time, system);
	return (0);
}

int	philo_thinking(t_system *system, t_philo *philo)
{
	if (check_stop(system))
		return (1);
	philo_print(system, philo, D_THINKING);
	return (0);
}
