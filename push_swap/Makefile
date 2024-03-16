# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: woonshin <woonshin@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/25 21:54:02 by woonshin          #+#    #+#              #
#    Updated: 2024/03/16 20:20:11 by woonshin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC			= cc
NAME		= push_swap
SRC_DIR		= ./
OBJ_DIR		= obj/
CFLAGS		= -Wall -Werror -Wextra

# Libft
LIBFT = libft
LIBFT_TARGET = libft.a

# Mandatory
SRC_FILES			= push_swap
SORT_FILES			= sort_dual_stack sort_utils sort_utils2 sort_utils3
STACK_FILES			= stack stack_operation stack_cleaner stack_swap stack_rotate stack_reverse_rotate stack_pop
INPUT_VALI_FILES	= input_validate
OBJ 				= $(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC_FILES)))
SORT_OBJ 			= $(addprefix $(OBJ_DIR), $(addsuffix .o, $(SORT_FILES)))
INPUT_VALI_OBJ 		= $(addprefix $(OBJ_DIR), $(addsuffix .o, $(INPUT_VALI_FILES)))
STACK_OBJ 			= $(addprefix $(OBJ_DIR), $(addsuffix .o, $(STACK_FILES)))

# Bonus
BONUS_NAME				= checker
SRC_BNS_FILES			= checker_bonus command_execution_bonus command_lst_bonus 
SORT_BNS_FILES			= sort_dual_stack_bonus sort_utils_bonus sort_utils2_bonus sort_utils3_bonus 
STACK_BNS_FILES			= stack_bonus stack_operation_bonus stack_cleaner_bonus stack_swap_bonus stack_rotate_bonus stack_reverse_rotate_bonus stack_pop_bonus 
INPUT_BNS_VALI_FILES	= input_validate_bonus
BNS_OBJ 				= $(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC_BNS_FILES)))
SORT_BNS_OBJ 			= $(addprefix $(OBJ_DIR), $(addsuffix .o, $(SORT_BNS_FILES)))
INPUT_VALI_BNS_OBJ 		= $(addprefix $(OBJ_DIR), $(addsuffix .o, $(INPUT_BNS_VALI_FILES)))
STACK_BNS_OBJ 			= $(addprefix $(OBJ_DIR), $(addsuffix .o, $(STACK_BNS_FILES)))

# GNL
GET_NEXT_LINE_FILES 	= get_next_line get_next_line_utils
GET_NEXT_LINE_OBJ		= $(addprefix $(OBJ_DIR), $(addsuffix .o, $(GET_NEXT_LINE_FILES)))
GET_NEXT_LINE_BNS_FILES = get_next_line_bonus get_next_line_utils_bonus
GET_NEXT_LINE_BNS_OBJ	= $(addprefix $(OBJ_DIR), $(addsuffix .o, $(GET_NEXT_LINE_FILES)))

all: $(NAME)

$(NAME): $(LIBFT_TARGET) $(OBJ) $(STACK_OBJ) $(SORT_OBJ) $(INPUT_VALI_OBJ) $(GET_NEXT_LINE_OBJ)
	$(CC) $(LIBFT_TARGET) $(INPUT_VALI_OBJ) $(OBJ) $(STACK_OBJ) $(SORT_OBJ) $(GET_NEXT_LINE_OBJ) -o $(NAME)

$(OBJ_DIR)%.o: %.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@ -I $(LIBFT) 

$(LIBFT_TARGET): 
	make -C libft
	mv libft/libft.a ./

$(OBJ_DIR): 
	mkdir $(OBJ_DIR)

$(BONUS_NAME): $(LIBFT_TARGET) $(BNS_OBJ) $(SORT_BNS_OBJ) $(INPUT_VALI_BNS_OBJ) $(STACK_BNS_OBJ) $(GET_NEXT_LINE_BNS_OBJ)
	$(CC) $(LIBFT_TARGET) $(BNS_OBJ) $(SORT_BNS_OBJ) $(INPUT_VALI_BNS_OBJ) $(STACK_BNS_OBJ) $(GET_NEXT_LINE_BNS_OBJ) -o $(BONUS_NAME)

bonus: $(BONUS_NAME)  

clean:
	make clean -C $(LIBFT)
	rm -rf $(OBJ_DIR)

fclean:	clean
	rm -f $(NAME)
	rm -f $(BONUS_NAME)
	rm -f $(LIBFT_TARGET)
	make fclean -C $(LIBFT)

re: fclean all

.PHONY:	all bonus clean fclean re 