/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woonshin <woonshin@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 13:48:53 by woonshin          #+#    #+#             */
/*   Updated: 2024/09/10 17:09:20 by woonshin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "process.h"

void	died_monitoring(void *args)
{
	long long	last_eat;
	t_philo_args	*philo_args;

	philo_args = (t_philo_args *)args;
	while (1)
	{
		sem_wait(philo_args->philo->eat_sem);
		last_eat = philo_args->philo->last_eat;
		sem_post(philo_args->philo->eat_sem);
		if (get_time() - last_eat > philo_args->system->args.life_time)
		{
			sem_wait(philo_args->system->print_sem);
			printf("%lld %d died\n", get_time() - philo_args->philo->start_time, philo_args->philo->id);
			stop_processes(philo_args->system);
			return ;
		}
		usleep(10);
	}
}

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
		usleep(system->args.eat_time / 2 * 1000);
		
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
	free(args);
}

void	fulll_monitoring(void *args)
{
	int			i;
	t_system	*system;

	system = (t_system *)args;
	i = 0;
	usleep(1000);
	while (i < system->args.philo_num)
	{
		sem_wait(system->full_sem);
		i++;
	}
	sem_wait(system->print_sem);
	printf("All philosophers are full\n");
	stop_processes(system);
}

void stop_processes(t_system *system)
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

void	process_monitoring(t_system *system)
{
	pthread_create(&system->monitoring_thread, NULL, (void *)fulll_monitoring, (void *)system);
	waitpid(-1, NULL, 0);
	stop_processes(system);
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
