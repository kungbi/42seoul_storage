/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_func.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woonshin <woonshin@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 13:43:50 by woonshin          #+#    #+#             */
/*   Updated: 2024/09/08 21:41:33 by woonshin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_func.h"

int	philo_fork(t_system *system, t_philo *philo)
{
	if (check_stop(philo))
		return(1);
	sem_wait(philo->left_fork);
	if (philo_print(system, philo, D_FORK))
	{
		sem_post(philo->left_fork);
		return(1);
	}
	if (system->args.philo_num == 1)
	{
		sem_post(philo->left_fork);
		return(1);
	}
	sem_wait(philo->right_fork);
	if (philo_print(system, philo, D_FORK))
	{
		sem_post(philo->left_fork);
		sem_post(philo->right_fork);
		return(1);
	}
	return (0);
}

int	philo_eating(t_system *system, t_philo *philo)
{
	if (check_stop(philo))
		return(1);
	if (philo_print(system, philo, D_EATING))
	{
		sem_post(philo->left_fork);
		sem_post(philo->right_fork);
		return(1);
	}
	sem_wait(philo->eat_sem);
	philo->last_eat = get_time();
	sem_post(philo->eat_sem);
	if (ft_usleep(system->args.eat_time, philo))
	{
		sem_post(philo->left_fork);
		sem_post(philo->right_fork);
		return(1);
	}
	sem_wait(philo->eat_sem);
	philo->eat_count++;
	sem_post(philo->eat_sem);
	if (philo->eat_count == system->args.eat_num)
	{
		sem_post(system->full_sem);
	}
	sem_post(philo->left_fork);
	sem_post(philo->right_fork);
	return (0);
}

int	philo_sleeping(t_system *system, t_philo *philo)
{
	if (check_stop(philo))
		return(1);
	if (philo_print(system, philo, D_SLEEPING))
		return(1);
	if (ft_usleep(system->args.sleep_time, philo))
		return(1);
	return (0);
}

int	philo_thinking(t_system *system, t_philo *philo)
{
	if (check_stop(philo))
		return(1);
	if (philo_print(system, philo, D_THINKING))
		return(1);
	return (0);
}
