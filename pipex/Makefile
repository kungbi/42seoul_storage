# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: woonshin <woonshin@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/29 13:19:28 by woonshin          #+#    #+#              #
#    Updated: 2024/03/02 01:38:25 by woonshin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= pipex
NAME_BNS		= pipex_bonus
LIBFT			= libft
LIBFT_TARGET	= libft.a
CFLAGS			= -Wall -Werror -Wextra
INCLUDES		= -I libft

GNL_FILES	= get_next_line get_next_line_utils
GNL_OBJ 	= $(addsuffix .o, $(GNL_FILES))

PIPEX_FILES 	= pipex input_validate input_validate2 pipex_fork utils
PIPEX_FILES_OBJ	= $(addsuffix .o, $(PIPEX_FILES))

PIPEX_FILES_BNS 	= pipex_bonus input_validate input_validate2 pipex_fork utils heredoc_bonus
PIPEX_FILES_OBJ_BNS	= $(addsuffix .o, $(PIPEX_FILES_BNS))

all: $(NAME)

$(LIBFT_TARGET):
	@make -C libft
	@mv libft/libft.a ./

$(NAME): $(LIBFT_TARGET) $(PIPEX_FILES_OBJ) $(GNL_OBJ)
	$(CC) $(LIBFT_TARGET) $(CFLAGS) $(GNL_OBJ) $(PIPEX_FILES_OBJ) -o $(NAME)

%.o : %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c -o $@ $<

clean:
	$(RM) $(PIPEX_FILES_OBJ)
	$(RM) $(PIPEX_FILES_OBJ_BNS)
	$(RM) $(GNL_OBJ)
	@make clean -C $(LIBFT)

fclean: clean
	$(RM) $(LIBFT_TARGET)
	$(RM) $(NAME)
	$(RM) $(NAME_BNS)
	@make fclean -C $(LIBFT)

re: fclean all

$(NAME_BNS): $(LIBFT_TARGET) $(PIPEX_FILES_OBJ_BNS) $(GNL_OBJ)
	$(CC) $(LIBFT_TARGET) $(CFLAGS) $(GNL_OBJ) $(PIPEX_FILES_OBJ_BNS) -o $(NAME_BNS)

bonus: $(NAME_BNS)


.PHONY:	all clean fclean re bonus