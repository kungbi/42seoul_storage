/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woonshin <woonshin@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 22:11:52 by woonshin          #+#    #+#             */
/*   Updated: 2024/09/08 18:13:32 by woonshin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_system	system;

	memset(&system, 0, sizeof(t_system));
	if (argc < 5 || 6 < argc)
		err_return(ARGS_ERR);
	args_init(argc, argv, &system.args);
	system_init(&system);
	process_start(&system);
	process_monitoring(&system);
	free_system(&system);
	return (0);
}
