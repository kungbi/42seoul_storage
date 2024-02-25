# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: woonshin <woonshin@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/16 00:39:58 by woonshin          #+#    #+#              #
#    Updated: 2024/02/25 16:12:15 by woonshin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC					= cc
NAME				= so_long
CFLAGS			= -Wall -Werror -Wextra
INCLUDES		= -I mlx -I libft

MLX					= mlx
MLX_TARGET	= libmlx.a
MLX_FLAGS		= -Lmlx -lmlx -framework OpenGL -framework AppKit

SL_FILES	= so_long map_input map_checker utils utils2 enemy render step_render key_control
GNL_FILES	= get_next_line get_next_line_utils

SL_SRC 		= $(addsuffix .c, $(SL_FILES))
SL_OBJ 		= $(addsuffix .o, $(SL_FILES))

GNL_SRC 	= $(addsuffix .c, $(GNL_FILES))
GNL_OBJ 	= $(addsuffix .o, $(GNL_FILES))

LIBFT = libft
LIBFT_TARGET = libft.a

all: $(NAME)

$(LIBFT_TARGET):
	make -C libft
	mv libft/libft.a ./

$(NAME): $(LIBFT_TARGET) $(MLX_TARGET) $(SL_OBJ) $(GNL_OBJ)
	$(CC) $(LIBFT_TARGET) $(CFLAGS) $(MLX_FLAGS) $(SL_OBJ) $(GNL_OBJ) -o $(NAME)

%.o : %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c -o $@ $<

$(MLX_TARGET):
	@make -C $(MLX)
	cp $(MLX)/$(MLX_TARGET) ./


clean:
	$(RM) $(SL_OBJ)
	$(RM) $(GNL_OBJ)
	$(RM) $(LIBFT_OBJ)
	$(RM) $(LIBFT_TARGET)
	@make clean -C $(MLX)
	@make clean -C $(LIBFT)

fclean: clean
	$(RM) $(NAME)
	$(RM) $(MLX_TARGET)
	@make fclean -C $(LIBFT)

re: fclean all

.PHONY:	all clean fclean re 