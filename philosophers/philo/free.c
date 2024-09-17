/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woonshin <woonshin@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 15:27:08 by woonshin          #+#    #+#             */
/*   Updated: 2024/09/17 20:37:35 by woonshin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "free.h"
#include "struct.h"

void	free_system(t_system *system)
{
	if (system->philos)
		free(system->philos);
	if (system->forks)
		free(system->forks);
	if (system->threads)
		free(system->threads);
}

void	mutex_destroy(t_system *system)
{
	int	i;

	i = 0;
	while (i < system->args.philo_num)
	{
		pthread_mutex_destroy(&system->forks[i]);
		pthread_mutex_destroy(&system->philos[i].eat_mutex);
		i++;
	}
	pthread_mutex_destroy(&system->stop_mutex);
	pthread_mutex_destroy(&system->print_mutex);
}
