/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_func3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woonshin <woonshin@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 22:28:19 by woonshin          #+#    #+#             */
/*   Updated: 2024/09/07 22:28:33 by woonshin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_func.h"

int	ft_usleep(long long time, t_system *system)
{
	long long	end_time;

	end_time = get_time() + time;
	while (get_time() < end_time)
	{
		if (check_stop(system))
			return (1);
		usleep(100);
	}
	return (0);
}

int	philo_print(t_system *system, t_philo *philo, int status)
{
	pthread_mutex_lock(&system->print_mutex);
	if (check_stop(system))
	{
		pthread_mutex_unlock(&system->print_mutex);
		return (1);
	}
	if (status == D_FORK)
		printf("%lld %d has taken a fork\n",
			get_time() - philo->start_time, philo->id);
	else if (status == D_EATING)
		printf("%lld %d is eating\n",
			get_time() - philo->start_time, philo->id);
	else if (status == D_SLEEPING)
		printf("%lld %d is sleeping\n",
			get_time() - philo->start_time, philo->id);
	else if (status == D_THINKING)
		printf("%lld %d is thinking\n",
			get_time() - philo->start_time, philo->id);
	else if (status == D_DIED)
		printf("%lld %d died\n",
			get_time() - philo->start_time, philo->id);
	pthread_mutex_unlock(&system->print_mutex);
	return (0);
}
