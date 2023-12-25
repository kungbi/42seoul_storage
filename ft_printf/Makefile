# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: woonshin <woonshin@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/25 21:54:02 by woonshin          #+#    #+#              #
#    Updated: 2023/12/25 23:22:32 by woonshin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		= gcc
NAME	= libftprintf.a
INCLUDE	= include
SRC_DIR	= src/
OBJ_DIR	= obj/
CFLAGS	= -Wall -Werror -Wextra
AR		= ar rcs

SRC_FILES	= ft_printf ft_print_ptr ft_print_hex ft_print_unsigned_int ft_print_nbr ft_print_str ft_print_char ft_memset
SRC 		= $(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC_FILES)))
OBJ 		= $(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC_FILES)))

all: $(NAME)

$(NAME): $(OBJ_DIR) $(OBJ)
	$(AR) $(NAME) $(OBJ)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -I $(INCLUDE) -c $< -o $@ 

$(OBJ_DIR):
	mkdir $(OBJ_DIR)

clean:
	rm -rf $(OBJ_DIR)

fclean:	clean
	rm -f $(NAME)

re: fclean all

.PHONY:	all clean fclean re