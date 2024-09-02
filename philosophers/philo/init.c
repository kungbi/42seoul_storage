/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woonshin <woonshin@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 16:23:09 by woonshin          #+#    #+#             */
/*   Updated: 2024/09/02 16:06:10 by woonshin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include "free.h"

void	args_init(int argc, char **argv, t_args *args)
{
	args->philo_num = ft_atoi(argv[1]);
	args->life_time = ft_atoi(argv[2]);
	args->eat_time = ft_atoi(argv[3]);
	args->sleep_time = ft_atoi(argv[4]);
	args->eat_num = -1;
	if (argc == 6)
		args->eat_num = ft_atoi(argv[5]);
	if (args->philo_num <= 0 || args->life_time <= 0
		|| args->eat_time < 0 || args->sleep_time < 0)
		err_return(ARGS_ERR);
	if (argc == 6 && args->eat_num < 0)
		err_return(ARGS_ERR);
}

void	philo_init(t_system *system)
{
	int	i;

	i = 0;
	while (i < system->args.philo_num)
	{
		system->philos[i].id = i;
		system->philos[i].eat_count = 0;
		system->philos[i].start_time = get_time() + i;
		system->philos[i].last_eat = 0;
		system->philos[i].left_fork = &system->forks[i];
		system->philos[i].right_fork = \
			&system->forks[(i + 1) % system->args.philo_num];
		if (pthread_mutex_init(&system->philos[i].print, NULL))
		{
			free_system(system);
			err_return(MUTEX_ERR);
		}
		i++;
	}
}

void	fork_mutex_init(t_system *system)
{
	int	i;

	i = 0;
	while (i < system->args.philo_num)
	{
		if (pthread_mutex_init(&system->forks[i], NULL))
		{
			free_system(system);
			err_return(MUTEX_ERR);
		}
		i++;
	}
}

void	system_init(t_system *system)
{
	system->stop_flag = 0;
	system->philos = (t_philo *)malloc(sizeof(t_philo) * system->args.philo_num);
	if (!system->philos)
		err_return(MALLOC_ERR);
	system->forks = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t)
			* system->args.philo_num);
	if (!system->forks)
	{
		free(system->philos);
		err_return(MALLOC_ERR);
	}
	fork_mutex_init(system);
	philo_init(system);
	system->threads = (pthread_t *)malloc(sizeof(pthread_t) * system->args.philo_num);
	if (!system->threads)
		err_return(MALLOC_ERR);
}
