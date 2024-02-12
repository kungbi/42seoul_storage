# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: woonshin <woonshin@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/25 21:54:02 by woonshin          #+#    #+#              #
#    Updated: 2024/02/12 20:50:17 by woonshin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		= gcc
NAME	= push_swap
INCLUDE	= include
SRC_DIR	= src/
OBJ_DIR	= obj/
# CFLAGS	= -Wall -Werror -Wextra

SRC_FILES	= push_swap
SRC 		= $(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC_FILES)))
OBJ 		= $(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC_FILES)))

INPUT_VALI_SRC 		= $(addprefix $(SRC_DIR), $(addsuffix .c, input_validate))
INPUT_VALI_OBJ 		= $(addprefix $(OBJ_DIR), $(addsuffix .o, input_validate))

SORT_FILES	= sort_dual_stack sort_utils sort_utils2 sort_utils3
SORT_SRC 		= $(addprefix $(SRC_DIR), $(addsuffix .c, $(SORT_FILES)))
SORT_OBJ 		= $(addprefix $(OBJ_DIR), $(addsuffix .o, $(SORT_FILES)))

STACK_FILES	= stack stack_operation stack_cleaner stack_swap stack_rotate stack_reverse_rotate stack_pop
STACK_SRC 		= $(addprefix $(SRC_DIR), $(addsuffix .c, $(STACK_FILES)))
STACK_OBJ 		= $(addprefix $(OBJ_DIR), $(addsuffix .o, $(STACK_FILES)))

LIBFT = libft
LIBFT_TARGET = libft.a

BONUS_NAME	= checker
BONUS_FILES	= bonus_checker bonus_command_execution
BONUS_SRC	= $(addprefix $(SRC_DIR), $(addsuffix .c, $(BONUS_FILES)))
BONUS_OBJ	= $(addprefix $(OBJ_DIR), $(addsuffix .o, $(BONUS_FILES)))

GET_NEXT_LINE_DIR = get_next_line/
GET_NEXT_LINE_NAME = get_next_line.a
GET_NEXT_LINE_FILES = get_next_line get_next_line_utils
GET_NEXT_LINE_SRC	= $(addprefix $(GET_NEXT_LINE_DIR), $(addsuffix .c, $(GET_NEXT_LINE_FILES)))
GET_NEXT_LINE_OBJ	= $(addprefix $(GET_NEXT_LINE_DIR), $(addsuffix .o, $(GET_NEXT_LINE_FILES)))

all: $(NAME)

$(NAME): $(LIBFT_TARGET) $(OBJ_DIR) $(OBJ) $(STACK_OBJ) $(SORT_OBJ) $(INPUT_VALI_OBJ) 
	$(CC) $(LIBFT_TARGET) $(INPUT_VALI_OBJ) $(OBJ) $(STACK_OBJ) $(SORT_OBJ) -o $(NAME)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -I $(INCLUDE) -I $(LIBFT) -I $(GET_NEXT_LINE_DIR) -c $< -o $@ 

$(LIBFT_TARGET): 
	make -C libft
	mv libft/libft.a ./

$(OBJ_DIR): 
	mkdir $(OBJ_DIR)

clean:
	rm -rf $(OBJ_DIR)
	make clean -C $(LIBFT)
	rm -rf $(GET_NEXT_LINE_OBJ)
	rm -rf $(BONUS_OBJ)

$(BONUS_NAME): $(BONUS_OBJ) $(GET_NEXT_LINE_NAME) 
	$(CC) $(BONUS_OBJ) $(INPUT_VALI_OBJ) $(GET_NEXT_LINE_OBJ) $(LIBFT_TARGET) $(SORT_OBJ) $(STACK_OBJ) -o $(BONUS_NAME)

bonus: all $(BONUS_NAME)

fclean:	clean
	rm -f $(NAME)
	rm -f $(LIBFT_TARGET)
	rm -f $(GET_NEXT_LINE_NAME)
	rm -f $(BONUS_NAME)
	make fclean -C $(LIBFT)

re: fclean all

$(GET_NEXT_LINE_NAME): $(GET_NEXT_LINE_OBJ)
	ar rsu $(GET_NEXT_LINE_NAME) $(GET_NEXT_LINE_OBJ) 
	
.PHONY:	all bonus clean fclean re 