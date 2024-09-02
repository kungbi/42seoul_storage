# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: woonshin <woonshin@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/29 22:12:43 by woonshin          #+#    #+#              #
#    Updated: 2024/08/11 16:21:31 by woonshin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC				= cc
NAME			= philo
LIBFT			= libft
LIBFT_TARGET	= libft.a
# CFLAGS			= -Wall -Werror -Wextra
INCLUDES		= -I libft -I header

SRC_FILES = $(shell find ./ -name "*.c" -d 1)
OBJ_FILES = $(SRC_FILES:.c=.o)


all: $(NAME)

$(LIBFT_TARGET):
	@make -C libft
	@mv libft/libft.a ./

$(NAME): $(LIBFT_TARGET) $(OBJ_FILES)
	$(CC) $(LIBFT_TARGET) $(CFLAGS) $(OBJ_FILES) -o $(NAME)

%.o : %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c -o $@ $<

clean:
	@make clean -C $(LIBFT)
	$(RM) $(OBJ_FILES)

fclean: clean
	$(RM) $(LIBFT_TARGET)
	$(RM) $(NAME)
	@make fclean -C $(LIBFT)

re: fclean all

bonus: .BONUS


.PHONY:	all clean fclean re bonus