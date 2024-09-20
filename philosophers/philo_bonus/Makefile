# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: woonshin <woonshin@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/29 22:12:43 by woonshin          #+#    #+#              #
#    Updated: 2024/09/20 20:46:00 by woonshin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC				= cc
NAME			= philo_bonus
CFLAGS			= -Wall -Werror -Wextra -pthread
INCLUDES		=  -I header

SRC_FILES = $(shell find ./ -name "*.c" -d 1)
OBJ_FILES = $(SRC_FILES:.c=.o)


all: $(NAME)

$(NAME): $(OBJ_FILES)
	$(CC) $(CFLAGS) $(OBJ_FILES) -o $(NAME)

%.o : %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c -o $@ $<

clean:
	$(RM) $(OBJ_FILES)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY:	all clean fclean re