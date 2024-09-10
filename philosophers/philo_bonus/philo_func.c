/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_func.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woonshin <woonshin@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 13:43:50 by woonshin          #+#    #+#             */
/*   Updated: 2024/09/10 17:08:58 by woonshin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_func.h"

int	philo_fork(t_system *system, t_philo *philo)
{
	sem_wait(philo->left_fork);
	if (philo_print(system, philo, D_FORK))
		return(sem_post(philo->left_fork), 1);
	if (system->args.philo_num == 1)
		return(sem_post(philo->left_fork), 1);
	sem_wait(philo->right_fork);
	philo_print(system, philo, D_FORK);
	return (0);
}

int	philo_eating(t_system *system, t_philo *philo)
{
	philo_print(system, philo, D_EATING);
	
	sem_wait(philo->eat_sem);
	philo->last_eat = get_time();
	sem_post(philo->eat_sem);
	
	usleep(system->args.eat_time * 1000);
	
	sem_wait(philo->eat_sem);
	philo->eat_count++;
	sem_post(philo->eat_sem);
	
	if (philo->eat_count == system->args.eat_num)
		sem_post(system->full_sem);
		
	sem_post(philo->left_fork);
	sem_post(philo->right_fork);
	return (0);
}

int	philo_sleeping(t_system *system, t_philo *philo)
{
	philo_print(system, philo, D_SLEEPING);
	usleep(system->args.sleep_time * 1000);
	return (0);
}

int	philo_thinking(t_system *system, t_philo *philo)
{
	philo_print(system, philo, D_THINKING);
	return (0);
}
