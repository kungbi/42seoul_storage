# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: woonshin <woonshin@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/29 13:19:28 by woonshin          #+#    #+#              #
#    Updated: 2024/02/29 19:00:04 by woonshin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= pipex
LIBFT			= libft
LIBFT_TARGET	= libft.a
# CFLAGS			= -Wall -Werror -Wextra
INCLUDES		= -I libft

PIPEX_FILES 	= pipex input_validate
PIPEX_FILES_SRC	= $(addsuffix .c, $(PIPEX_FILES))
PIPEX_FILES_OBJ	= $(addsuffix .o, $(PIPEX_FILES))

all: $(NAME)

$(LIBFT_TARGET):
	@make -C libft
	@mv libft/libft.a ./

$(NAME): $(LIBFT_TARGET) $(PIPEX_FILES_OBJ)
	$(CC) $(LIBFT_TARGET) $(CFLAGS) $(PIPEX_FILES_OBJ) -o $(NAME)

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