/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woonshin <woonshin@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 16:23:09 by woonshin          #+#    #+#             */
/*   Updated: 2024/09/09 13:40:26 by woonshin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include "free.h"

int	args_init(int argc, char **argv, t_args *args)
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
		return (err_return(ARGS_ERR));
	if (argc == 6 && args->eat_num < 0)
		return (err_return(ARGS_ERR));
	return (0);
}

int	philo_init(t_system *system)
{
	int	i;

	i = 0;
	while (i < system->args.philo_num)
	{
		system->philos[i].id = i;
		system->philos[i].eat_count = 0;
		system->philos[i].start_time = get_time() + system->args.philo_num;
		system->philos[i].last_eat = system->philos[i].start_time;
		system->philos[i].left_fork = &system->forks[i];
		system->philos[i].right_fork = \
			&system->forks[(i + 1) % system->args.philo_num];
		if (pthread_mutex_init(&system->philos[i].eat_mutex, NULL))
		{
			free_system(system);
			return (err_return(MUTEX_ERR));
		}
		i++;
	}
	return (0);
}

int	fork_mutex_init(t_system *system)
{
	int	i;

	i = 0;
	while (i < system->args.philo_num)
	{
		if (pthread_mutex_init(&system->forks[i], NULL))
		{
			free_system(system);
			return (err_return(MUTEX_ERR));
		}
		i++;
	}
	return (0);
}

int	system_init(t_system *system)
{
	system->stop_flag = 0;
	system->philos = (t_philo *)malloc(sizeof(t_philo)
			* system->args.philo_num);
	if (!system->philos)
		return (err_return(MALLOC_ERR));
	system->forks = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t)
			* system->args.philo_num);
	if (!system->forks)
		return (free(system->philos), err_return(MALLOC_ERR));
	if (fork_mutex_init(system) || philo_init(system))
		return (free_system(system), err_return(ERROR));
	system->threads = (pthread_t *)malloc(sizeof(pthread_t)
			* system->args.philo_num);
	if (!system->threads)
		return (err_return(MALLOC_ERR));
	if (pthread_mutex_init(&system->stop_mutex, NULL)
		|| pthread_mutex_init(&system->print_mutex, NULL))
		return (free_system(system), err_return(MUTEX_ERR));
	return (0);
}
