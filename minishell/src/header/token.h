/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woonshin <woonshin@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 13:23:29 by woonshin          #+#    #+#             */
/*   Updated: 2024/06/05 14:49:56 by woonshin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOKEN_H
#define TOKEN_H

# define T_NULL 0
# define T_WORD 1
# define T_PIPE 2
# define T_REDIRECT 3
# define T_DOUBLE_QUOTES 4
# define T_SINGLE_QUOTES 5
typedef struct s_token {
	int		type;
	char	*str;
}	t_token;

#endif