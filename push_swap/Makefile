# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: woonshin <woonshin@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/25 21:54:02 by woonshin          #+#    #+#              #
#    Updated: 2024/02/04 23:25:28 by woonshin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		= gcc
NAME	= push_swap
INCLUDE	= include
SRC_DIR	= src/
OBJ_DIR	= obj/
CFLAGS	= -Wall -Werror -Wextra

SRC_FILES	= push_swap stack input_validate
SRC 		= $(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC_FILES)))
OBJ 		= $(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC_FILES)))

LIBFT = libft
LIBFT_TARGET = libft.a

all: $(NAME)

$(NAME): $(LIBFT_TARGET) $(OBJ_DIR) $(OBJ) 
	$(CC) $(LIBFT_TARGET) $(OBJ_DIR)*.o -o $(NAME)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -I $(INCLUDE) -I $(LIBFT) -c $< -o $@ 

$(LIBFT_TARGET): 
	make -C libft
	mv libft/libft.a ./

$(OBJ_DIR): 
	mkdir $(OBJ_DIR)

clean:
	rm -rf $(OBJ_DIR)
	make clean -C $(LIBFT)

fclean:	clean
	rm -f $(NAME)
	rm -f $(LIBFT_TARGET)
	make fclean -C $(LIBFT)

re: fclean all

.PHONY:	all clean fclean re