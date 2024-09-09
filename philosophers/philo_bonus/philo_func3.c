/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_func3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woonshin <woonshin@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 22:28:19 by woonshin          #+#    #+#             */
/*   Updated: 2024/09/08 21:09:36 by woonshin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_func.h"

int	ft_usleep(long long time, t_philo *philo)
{
	long long	end_time;

	end_time = get_time() + time;
	while (get_time() < end_time)
	{
		if (check_stop(philo))
			return (1);
		usleep(100);
	}
	return (0);
}

int	philo_print(t_system *system, t_philo *philo, int status)
{
	sem_wait(system->print_sem);
	if (check_stop(philo))
	{
		sem_post(system->print_sem);
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
	sem_post(system->print_sem);
	return (0);
}

void	ft_sem_open(sem_t **sem, char *name, int num, int value)
{
	char	*tmp;

	if (0 < num)
		tmp = ft_chrjoin(name, num + '0');
	else
		tmp = name;
	*sem = sem_open(tmp, O_CREAT | O_TRUNC | O_EXCL, 0644, value);
	if (*sem == SEM_FAILED)
	{
		free(tmp);
		err_return(SEM_ERR);
	}
	sem_unlink(tmp);
	if (0 < num)
		free(tmp);
}