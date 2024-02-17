# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: woonshin <woonshin@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/16 00:39:58 by woonshin          #+#    #+#              #
#    Updated: 2024/02/17 13:52:38 by woonshin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC					= cc
NAME				= so_long
# CFLAGS			= -Wall -Werror -Wextra
INCLUDES		= -I mlx

MLX					= mlx
MLX_TARGET	= libmlx.a
MLX_FLAGS		= -Lmlx -lmlx -framework OpenGL -framework AppKit

SL_FILES	= so_long map_input map_checker utils
GNL_FILES	= get_next_line get_next_line_utils
LIBFT_FILES	= ft_atoi ft_calloc ft_putstr_fd ft_strlcpy ft_strlen ft_isdigit ft_memset ft_strncmp

SL_SRC 		= $(addsuffix .c, $(SL_FILES))
SL_OBJ 		= $(addsuffix .o, $(SL_FILES))

GNL_SRC 	= $(addsuffix .c, $(GNL_FILES))
GNL_OBJ 	= $(addsuffix .o, $(GNL_FILES))

LIBFT_SRC 	= $(addsuffix .c, $(LIBFT_FILES))
LIBFT_OBJ 	= $(addsuffix .o, $(LIBFT_FILES))

all: $(NAME)

$(NAME): $(MLX_TARGET) $(SL_OBJ) $(GNL_OBJ) $(LIBFT_OBJ)
	$(CC) $(CFLAGS) $(MLX_FLAGS) $(SL_OBJ) $(GNL_OBJ) $(LIBFT_OBJ) -o $(NAME)

%.o : %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c -o $@ $<

$(MLX_TARGET):
	@make -C $(MLX)
	cp $(MLX)/$(MLX_TARGET) ./


clean:
	$(RM) $(SL_OBJ)
	$(RM) $(GNL_OBJ)
	$(RM) $(LIBFT_OBJ)
	make clean -C $(MLX)

fclean: clean
	$(RM) $(NAME)
	$(RM) $(MLX_TARGET)

re: fclean all

.PHONY:	all clean fclean re 