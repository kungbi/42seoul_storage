# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: woonshin <woonshin@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/29 13:19:28 by woonshin          #+#    #+#              #
#    Updated: 2024/06/22 16:06:12 by woonshin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC				= cc
NAME			= pipex
NAME_BNS		= pipex_bonus
LIBFT			= libft
LIBFT_TARGET	= libft.a
CFLAGS			= -Wall -Werror -Wextra
INCLUDES		= -I libft

GNL_FILES		= gnl gnl_utils
PIPEX_FILES 	= pipex input_validate input_validate2 pipex_fork utils command_split delimiter_counter

GNL_BNS_FILES	= gnl_bonus gnl_utils_bonus 
PIPEX_FILES_BNS = pipex_bonus input_validate_bonus input_validate2_bonus pipex_fork_bonus utils_bonus heredoc_bonus command_split_bonus delimiter_counter_bonus

GNL_OBJ 			= $(addsuffix .o, $(GNL_FILES))
GNL_BNS_OBJ 		= $(addsuffix .o, $(GNL_BNS_FILES))

PIPEX_FILES_OBJ		= $(addsuffix .o, $(PIPEX_FILES))
PIPEX_FILES_OBJ_BNS	= $(addsuffix .o, $(PIPEX_FILES_BNS))

all: $(NAME)

$(LIBFT_TARGET):
	@make -C libft
	@mv libft/libft.a ./

$(NAME): $(LIBFT_TARGET) $(PIPEX_FILES_OBJ) $(GNL_OBJ)
	@$(RM) $(PIPEX_FILES_OBJ_BNS)
	@$(RM) $(GNL_BNS_OBJ)
	$(CC) $(LIBFT_TARGET) $(CFLAGS) $(PIPEX_FILES_OBJ) $(GNL_OBJ) -o $(NAME)
	@$(RM) .BONUS

%.o : %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c -o $@ $<

clean:
	$(RM) $(PIPEX_FILES_OBJ)
	$(RM) $(GNL_OBJ)
	$(RM) $(PIPEX_FILES_OBJ_BNS)
	$(RM) $(GNL_BNS_OBJ)
	@make clean -C $(LIBFT)

fclean: clean
	$(RM) $(LIBFT_TARGET)
	$(RM) $(NAME)
	@make fclean -C $(LIBFT)

re: fclean all

.BONUS: $(LIBFT_TARGET) $(PIPEX_FILES_OBJ_BNS) $(GNL_BNS_OBJ)
	$(RM) $(PIPEX_FILES_OBJ)
	$(RM) $(GNL_OBJ)
	$(CC) $(LIBFT_TARGET) $(CFLAGS) $(GNL_BNS_OBJ) $(PIPEX_FILES_OBJ_BNS) -o $(NAME)
	@touch .BONUS

bonus: .BONUS


.PHONY:	all clean fclean re bonus