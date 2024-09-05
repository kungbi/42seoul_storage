/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woonshin <woonshin@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 15:27:08 by woonshin          #+#    #+#             */
/*   Updated: 2024/09/04 16:44:37 by woonshin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "free.h"
#include "struct.h"

void	free_system(t_system *system)
{
	int	i;

	i = 0;
	while (i < system->args.philo_num)
	{
		pthread_mutex_destroy(&system->forks[i]);
		i++;
	}
	free(system->philos);
	free(system->forks);
	free(system->threads);
}
