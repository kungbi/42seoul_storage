/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_func2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woonshin <woonshin@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 20:55:16 by woonshin          #+#    #+#             */
/*   Updated: 2024/09/05 13:55:42 by woonshin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_func.h"

int	check_philo(t_system *system)
{
	int	i;
	int	full_count;

	i = 0;
	full_count = 0;
	while (i < system->args.philo_num)
	{
		pthread_mutex_lock(&system->philos[i].eat_mutex);
		if (system->args.eat_num != -1
			&& system->philos[i].eat_count >= system->args.eat_num)
			full_count++;
		else if (get_time() - system->philos[i].last_eat
			> system->args.life_time)
		{
			philo_print(system, &system->philos[i], D_DIED);
			system->stop_flag = 1;
		}
		pthread_mutex_unlock(&system->philos[i].eat_mutex);
		i++;
	}
	if (full_count == system->args.philo_num)
		system->stop_flag = 1;
	return (system->stop_flag);
}

int	ft_usleep(long long time, t_system *system)
{
	long long	end_time;

	end_time = get_time() + time;
	while (get_time() < end_time)
	{
		if (system->stop_flag)
			return (1);
		usleep(100);
	}
	return (0);
}

int	philo_print(t_system *system, t_philo *philo, int status)
{
	pthread_mutex_lock(&system->print_mutex);
	if (system->stop_flag)
	{
		pthread_mutex_unlock(&system->print_mutex);
		return (1);
	}
	if (status == D_FORK)
		printf("%lld %d has taken a fork\n",
			get_time() - system->start_time, philo->id);
	else if (status == D_EATING)
		printf("%lld %d is eating\n",
			get_time() - system->start_time, philo->id);
	else if (status == D_SLEEPING)
		printf("%lld %d is sleeping\n",
			get_time() - system->start_time, philo->id);
	else if (status == D_THINKING)
		printf("%lld %d is thinking\n",
			get_time() - system->start_time, philo->id);
	else if (status == D_DIED)
		printf("%lld %d died\n",
			get_time() - system->start_time, philo->id);
	pthread_mutex_unlock(&system->print_mutex);
	return (0);
}
