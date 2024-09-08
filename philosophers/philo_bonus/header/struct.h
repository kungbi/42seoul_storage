/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woonshin <woonshin@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 15:28:20 by woonshin          #+#    #+#             */
/*   Updated: 2024/09/08 21:28:05 by woonshin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H
# include <semaphore.h>

typedef struct s_args
{
	int	philo_num;
	int	life_time;
	int	eat_time;
	int	sleep_time;
	int	eat_num;
}	t_args;

typedef struct s_philo
{
	int				id;
	int				eat_count;
	int				stop_flag;
	long long		start_time;
	long long		last_eat;
	int				life_time;
	sem_t			*left_fork;
	sem_t			*right_fork;
	sem_t			*eat_sem;
	sem_t			*stop_sem;
}	t_philo;

typedef struct s_system
{
	t_args			args;
	int				start_flag;
	int				*pids;
	t_philo			*philos;
	sem_t			**forks;
	sem_t			*print_sem;
	sem_t			*full_sem;
	pthread_t		monitoring_thread;
}	t_system;

typedef struct s_philo_args
{
	t_system	*system;
	t_philo		*philo;
}	t_philo_args;

#endif