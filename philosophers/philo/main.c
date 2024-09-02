/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woonshin <woonshin@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 22:11:52 by woonshin          #+#    #+#             */
/*   Updated: 2024/09/02 16:09:58 by woonshin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	thread_func(void *data)
{
	t_philo	*philo;

	philo = (t_philo *)data;
}

void	monitor(t_system *system)
{
	// int	i;

	// i = 0;
	// while (i < system->args.philo_num)
	// {
	// 	if (system->args.eat_num != -1 && \
	// 		system->philos[i].eat_count >= system->args.eat_num)
	// 		system->stop_flag = 1;
	// 	if (system->stop_flag)
	// 		break ;
	// 	i++;
	// }
}

void	thread_start(t_system *system)
{
	int	i;

	i = 0;
	while (i < system->args.philo_num)
	{
		if (pthread_create(&system->threads[i], NULL, \
			(void *(*)(void *))thread_func, &system->philos[i]))
		{
			free_system(system);
			err_return(MALLOC_ERR);
		}
		i++;
	}
	i = 0;
	while (i < system->args.philo_num)
	{
		pthread_join(system->threads[i], NULL);
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_system	system;

	if (argc < 5 || 6 < argc)
		err_return(ARGS_ERR);
	args_init(argc, argv, &system.args);
	system_init(&system);
	thread_start(&system);
	free_system(&system);
	return (0);
}
