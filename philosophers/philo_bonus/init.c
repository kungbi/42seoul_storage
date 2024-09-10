/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woonshin <woonshin@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 16:23:09 by woonshin          #+#    #+#             */
/*   Updated: 2024/09/10 17:38:36 by woonshin         ###   ########.fr       */
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
	int		i;

	i = 0;
	while (i < system->args.philo_num)
	{
		system->philos[i].id = i;
		system->philos[i].eat_count = 0;
		system->philos[i].start_time
			= system->start_time + system->args.philo_num;
		system->philos[i].last_eat = system->philos[i].start_time;
		system->philos[i].life_time = system->args.life_time;
		system->philos[i].left_fork = system->forks[i];
		system->philos[i].right_fork = \
			system->forks[(i + 1) % system->args.philo_num];
		ft_sem_open(&system->philos[i].eat_sem, "eat_sem", i, 1);
		i++;
	}
}

void	fork_sem_init(t_system *system)
{
	int		i;

	i = 0;
	while (i < system->args.philo_num)
	{
		ft_sem_open(&system->forks[i], "forks", i, 1);
		i++;
	}
}

void	system_init(t_system *system)
{
	system->philos = (t_philo *)malloc(sizeof(t_philo)
			* system->args.philo_num);
	if (!system->philos)
		err_return(MALLOC_ERR);
	system->forks = (sem_t **)malloc(sizeof(sem_t *)
			* system->args.philo_num);
	if (!system->forks)
	{
		free(system->philos);
		err_return(MALLOC_ERR);
	}
	system->pids = (int *)malloc(sizeof(int) * system->args.philo_num);
	if (!system->pids)
	{
		free(system->philos);
		free(system->forks);
		err_return(MALLOC_ERR);
	}
	system->start_time = get_time();
	fork_sem_init(system);
	philo_init(system);
	ft_sem_open(&system->print_sem, "print_sem", -1, 1);
	ft_sem_open(&system->full_sem, "full_sem", -1, system->args.philo_num);
}
