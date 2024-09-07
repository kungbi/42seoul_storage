/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_func.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woonshin <woonshin@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 13:43:50 by woonshin          #+#    #+#             */
/*   Updated: 2024/09/07 19:44:07 by woonshin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_func.h"

int	philo_fork(t_system *system, t_philo *philo)
{
	if (check_stop(system))
		return (1);
	if (system->args.philo_num == 1)
	{
		pthread_mutex_lock(philo->left_fork);
		philo_print(system, philo, D_FORK);
		pthread_mutex_unlock(philo->left_fork);
		return (1);
	}
	pthread_mutex_lock(philo->left_fork);
	if (philo_print(system, philo, D_FORK))
	{
		pthread_mutex_unlock(philo->left_fork);
		return (1);
	}
	pthread_mutex_lock(philo->right_fork);
	if (philo_print(system, philo, D_FORK))
	{
		pthread_mutex_unlock(philo->left_fork);
		pthread_mutex_unlock(philo->right_fork);
		return (1);
	}
	return (0);
}

int	philo_eating(t_system *system, t_philo *philo)
{
	int	ret;

	ret = 0;
	if (check_stop(system))
		return (1);
	if (philo_print(system, philo, D_EATING))
	{
		pthread_mutex_unlock(philo->left_fork);
		pthread_mutex_unlock(philo->right_fork);
		return (1);
	}

	pthread_mutex_lock(&philo->eat_mutex);
	philo->last_eat = get_time();
	pthread_mutex_unlock(&philo->eat_mutex);

	if (ft_usleep(system->args.eat_time, system))
	{
		pthread_mutex_unlock(philo->left_fork);
		pthread_mutex_unlock(philo->right_fork);
		return (1);
	}

	pthread_mutex_lock(&philo->eat_mutex);
	philo->eat_count++;
	pthread_mutex_unlock(&philo->eat_mutex);

	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
	
	return (ret);
}

int	philo_sleeping(t_system *system, t_philo *philo)
{
	if (check_stop(system))
		return (1);
	if (philo_print(system, philo, D_SLEEPING))
		return (1);
	if (ft_usleep(system->args.sleep_time, system))
		return (1);
	return (0);
}

int	philo_thinking(t_system *system, t_philo *philo)
{
	if (check_stop(system))
		return (1);
	if (philo_print(system, philo, D_THINKING))
		return (1);
	return (0);
}
