/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_func2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woonshin <woonshin@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 20:55:16 by woonshin          #+#    #+#             */
/*   Updated: 2024/09/10 17:40:36 by woonshin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_func.h"

void	ft_usleep(int sleep_time)
{
	long long	start_time;

	start_time = get_time();
	while (get_time() - start_time < sleep_time)
		usleep(100);
}

int	philo_print(t_system *system, t_philo *philo, int status)
{
	sem_wait(system->print_sem);
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
	if (status != D_DIED)
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

void	stop_processes(t_system *system)
{
	int	i;

	i = 0;
	while (i < system->args.philo_num)
	{
		kill(system->pids[i], SIGINT);
		i++;
	}
	exit(0);
}
