/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_func2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woonshin <woonshin@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 20:55:16 by woonshin          #+#    #+#             */
/*   Updated: 2024/09/08 20:45:59 by woonshin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_func.h"

int	check_stop(t_philo *philo)
{
	int	ret;

	sem_wait(philo->stop_sem);
	ret = philo->stop_flag;
	sem_post(philo->stop_sem);
	return (ret);
}

int	stop_philo(t_philo *philo)
{
	sem_wait(philo->stop_sem);
	philo->stop_flag = 1;
	sem_post(philo->stop_sem);
	return (1);
}
