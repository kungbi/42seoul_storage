/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woonshin <woonshin@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 13:49:18 by woonshin          #+#    #+#             */
/*   Updated: 2024/09/10 17:40:40 by woonshin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROCESS_H
# define PROCESS_H
# include "struct.h"
# include "error.h"
# include "free.h"
# include "philo_func.h"

void	process_func(t_system *system, int id);
void	process_start(t_system *system);

#endif