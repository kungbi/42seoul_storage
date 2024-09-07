/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woonshin <woonshin@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 15:28:20 by woonshin          #+#    #+#             */
/*   Updated: 2024/09/07 13:08:39 by woonshin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H
# include <pthread.h>

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
	long long		start_time;
	long long		last_eat;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	pthread_mutex_t	eat_mutex;
}	t_philo;

typedef struct s_system
{
	long long		start_time;
	t_args			args;
	int				full_count;
	int				stop_flag;
	int				start_flag;
	t_philo			*philos;
	pthread_t		*threads;
	pthread_mutex_t	*forks;
	pthread_mutex_t	stop_mutex;
	pthread_mutex_t	print_mutex;
	pthread_mutex_t	full_mutex;
}	t_system;

typedef struct s_philo_args
{
	t_system	*system;
	t_philo		*philo;
}	t_philo_args;

#endif