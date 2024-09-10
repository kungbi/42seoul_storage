/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woonshin <woonshin@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 15:27:08 by woonshin          #+#    #+#             */
/*   Updated: 2024/09/09 17:01:43 by woonshin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "free.h"

void	free_system(t_system *system)
{
	int		i;

	i = 0;
	while (i < system->args.philo_num)
	{
		sem_close(system->philos[i].eat_sem);
		sem_close(system->forks[i]);
		i++;
	}
	sem_close(system->print_sem);
	sem_close(system->full_sem);
	free(system->philos);
	free(system->forks);
}
