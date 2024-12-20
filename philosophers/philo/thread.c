/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woonshin <woonshin@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 13:48:53 by woonshin          #+#    #+#             */
/*   Updated: 2024/09/07 22:45:22 by woonshin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "thread.h"

void	thread_func(void *data)
{
	t_philo_args	*philo_args;
	t_system		*system;
	t_philo			*philo;

	philo_args = (t_philo_args *)data;
	system = philo_args->system;
	philo = philo_args->philo;
	while (get_time() < philo->start_time)
		usleep(100);
	if (philo->id % 2)
		ft_usleep(system->args.eat_time / 2, system);
	while (1)
	{
		if (philo_fork(system, philo))
			break ;
		if (philo_eating(system, philo))
			break ;
		if (philo_sleeping(system, philo))
			break ;
		if (philo_thinking(system, philo))
			break ;
	}
	free(philo_args);
}

void	monitoring(t_system *system)
{
	while (1)
	{
		if (check_stop(system))
			break ;
		if (check_philo(system))
			break ;
		ft_usleep(5, system);
	}
}

void	thread_start(t_system *system)
{
	int				i;
	t_philo_args	*philo_args;

	i = 0;
	while (i < system->args.philo_num)
	{
		philo_args = (t_philo_args *)malloc(sizeof(t_philo_args));
		if (!philo_args)
			err_return(MALLOC_ERR);
		philo_args->system = system;
		philo_args->philo = &system->philos[i];
		if (pthread_create(&system->threads[i], NULL, \
			(void *(*)(void *))thread_func, philo_args))
			err_return(MALLOC_ERR);
		i++;
	}
	system->start_time = get_time();
	monitoring(system);
	i = 0;
	while (i < system->args.philo_num)
		pthread_join(system->threads[i++], NULL);
}
