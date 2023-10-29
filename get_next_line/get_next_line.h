/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woonshin <woonshin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 16:27:35 by woonshin          #+#    #+#             */
/*   Updated: 2023/10/29 16:35:34 by woonshin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifdef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFFER_SIZE 1024
# include <stdlib.h>
# include <unistd.h>

char	*get_next_line(int fd);

#endif