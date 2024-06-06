# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: woonshin <woonshin@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/29 13:19:28 by woonshin          #+#    #+#              #
#    Updated: 2024/06/05 13:17:13 by woonshin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC				= cc
NAME			= minishell
LIBFT			= libft
LIBFT_TARGET	= libft.a
CFLAGS			= -Wall -Werror -Wextra
INCLUDES		= -I libft -I header 




all: $(NAME)

$(LIBFT_TARGET):
	@make -C libft
	@mv libft/libft.a ./

$(NAME): $(LIBFT_TARGET)
	$(CC) $(LIBFT_TARGET) $(CFLAGS) -o $(NAME)

%.o : %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c -o $@ $<

clean:
	$(RM) $(PIPEX_FILES_OBJ)
	@make clean -C $(LIBFT)

fclean: clean
	$(RM) $(LIBFT_TARGET)
	$(RM) $(NAME)
	@make fclean -C $(LIBFT)

re: fclean all


.PHONY:	all clean fclean re bonus