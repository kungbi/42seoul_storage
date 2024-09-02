/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woonshin <woonshin@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 15:28:20 by woonshin          #+#    #+#             */
/*   Updated: 2024/09/02 16:06:00 by woonshin         ###   ########.fr       */
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
	pthread_mutex_t	print;
}	t_philo;

typedef struct s_system
{
	t_args			args;
	int				stop_flag;
	t_philo			*philos;
	pthread_mutex_t	*forks;
	pthread_t		*threads;
}	t_system;

#endif