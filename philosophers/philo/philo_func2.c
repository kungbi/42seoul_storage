/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_func2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woonshin <woonshin@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 20:55:16 by woonshin          #+#    #+#             */
/*   Updated: 2024/09/07 19:33:45 by woonshin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_func.h"

int	check_stop(t_system *system)
{
	int	ret;

	pthread_mutex_lock(&system->stop_mutex);
	ret = system->stop_flag;
	pthread_mutex_unlock(&system->stop_mutex);
	return (ret);
}

int stop_philo(t_system *system)
{
	pthread_mutex_lock(&system->stop_mutex);
	system->stop_flag = 1;
	pthread_mutex_unlock(&system->stop_mutex);
	return (1);
}

int check_dead(t_system *system, t_philo *philo)
{
	pthread_mutex_lock(&philo->eat_mutex);
	if (system->args.life_time < get_time() - philo->last_eat)
	{
		pthread_mutex_unlock(&philo->eat_mutex);
		philo_print(system, philo, D_DIED);
		stop_philo(system);
		return (1);
	}
	pthread_mutex_unlock(&philo->eat_mutex);
	return (0);
}

int	check_full(t_system *system, t_philo *philo)
{
	int eat_count; 
	
	if (system->args.eat_num == -1)
		return (0);
	pthread_mutex_lock(&philo->eat_mutex);
	eat_count = philo->eat_count;
	pthread_mutex_unlock(&philo->eat_mutex);
	
	if (eat_count == system->args.eat_num)
		return (1);
	return (0);
}

int	check_philo(t_system *system)
{
	int	i;
	int	full_count;

	i = 0;
	full_count = 0;
	while (i < system->args.philo_num)
	{
		if (check_dead(system, &system->philos[i]))
			return (1);

		if (check_full(system, &system->philos[i]))
			full_count++;
		pthread_mutex_unlock(&system->philos[i].eat_mutex);
		i++;
	}
	if (full_count == system->args.philo_num)
	{
		pthread_mutex_lock(&system->print_mutex);
		printf("All philosophers are full\n");
		pthread_mutex_unlock(&system->print_mutex);
		stop_philo(system);
		
		return (1);
	}
	return (system->stop_flag);
}

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
