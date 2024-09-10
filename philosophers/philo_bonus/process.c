/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woonshin <woonshin@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 13:48:53 by woonshin          #+#    #+#             */
/*   Updated: 2024/09/10 17:40:16 by woonshin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "process.h"

void	process_func(t_system *system, int id)
{
	t_philo			*philo;
	pthread_t		died_thread;
	t_philo_args	*args;

	args = malloc(sizeof(t_philo_args));
	if (!args)
		err_return(MALLOC_ERR);
	args->system = system;
	args->philo = &system->philos[id];
	philo = &system->philos[id];
	pthread_create(&died_thread, NULL, (void *)died_monitoring, (void *)args);
	while (get_time() < philo->start_time)
		usleep(100);
	if (philo->id % 2)
		ft_usleep(system->args.eat_time / 2);
	while (1)
	{
		philo_fork(system, philo);
		philo_eating(system, philo);
		philo_sleeping(system, philo);
		philo_thinking(system, philo);
	}
	free(args);
}

void	process_start(t_system *system)
{
	int		i;
	int		pid;

	i = 0;
	while (i < system->args.philo_num)
	{
		pid = fork();
		if (pid < 0)
			err_return(FORK_ERR);
		if (pid == 0)
		{
			sem_wait(system->full_sem);
			process_func(system, i);
			exit(0);
		}
		system->pids[i] = pid;
		i++;
	}
	usleep(system->args.philo_num);
}
