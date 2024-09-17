/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woonshin <woonshin@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 17:36:08 by woonshin          #+#    #+#             */
/*   Updated: 2024/09/17 20:54:35 by woonshin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_func.h"

void	process_monitoring(t_system *system)
{
	pthread_create(&system->monitoring_thread, NULL,
		(void *)fulll_monitoring, (void *)system);
	waitpid(-1, NULL, 0);
	stop_processes(system);
}

void	fulll_monitoring(void *args)
{
	int			i;
	t_system	*system;

	system = (t_system *)args;
	i = 0;
	ft_usleep(10);
	while (i < system->args.philo_num)
	{
		sem_wait(system->full_sem);
		i++;
	}
	sem_wait(system->print_sem);
	stop_processes(system);
}

void	died_monitoring(void *args)
{
	long long		last_eat;
	t_philo_args	*philo_args;

	philo_args = (t_philo_args *)args;
	while (1)
	{
		sem_wait(philo_args->philo->eat_sem);
		last_eat = philo_args->philo->last_eat;
		sem_post(philo_args->philo->eat_sem);
		if (get_time() - last_eat > philo_args->system->args.life_time)
		{
			philo_print(philo_args->system, philo_args->philo, D_DIED);
			stop_processes(philo_args->system);
			return ;
		}
		usleep(10);
	}
}
