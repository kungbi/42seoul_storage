/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woonshin <woonshin@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 15:26:36 by woonshin          #+#    #+#             */
/*   Updated: 2024/09/17 20:36:51 by woonshin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FREE_H
# define FREE_H
# include <stdlib.h>
# include "struct.h"

void	free_system(t_system *system);
void	mutex_destroy(t_system *system);

#endif