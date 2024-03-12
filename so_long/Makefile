# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: woonshin <woonshin@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/16 00:39:58 by woonshin          #+#    #+#              #
#    Updated: 2024/03/12 17:19:00 by woonshin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC				= cc
NAME			= so_long
NAME_BNS		= so_long_bonus
# CFLAGS			= -Wall -Werror -Wextra
INCLUDES		= -I mlx -I libft

MLX				= mlx
MLX_TARGET		= libmlx.a
MLX_FLAGS		= -Lmlx -lmlx -framework OpenGL -framework AppKit

LIBFT = libft
LIBFT_TARGET = libft.a

SL_FILES	= so_long map_input map_checker utils utils2 utils3 enemy render step_render key_control game_free
SL_FILES_BNS= so_long_bonus map_input_bonus map_checker_bonus utils_bonus utils2_bonus utils3_bonus enemy_bonus render_bonus step_render_bonus key_control_bonus game_free_bonus
GNL_FILES	= get_next_line get_next_line_utils

SL_SRC 		= $(addsuffix .c, $(SL_FILES))
SL_OBJ 		= $(addsuffix .o, $(SL_FILES))

GNL_SRC 	= $(addsuffix .c, $(GNL_FILES))
GNL_OBJ 	= $(addsuffix .o, $(GNL_FILES))

SL_SRC_BNS 	= $(addsuffix .c, $(SL_FILES_BNS))
SL_OBJ_BNS 	= $(addsuffix .o, $(SL_FILES_BNS))


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
	$(RM) $(SL_OBJ_BNS)
	$(RM) $(GNL_OBJ_BNS)

	@make clean -C $(MLX)
	@make clean -C $(LIBFT)

fclean: clean
	$(RM) $(NAME)
	$(RM) $(NAME_BNS)
	$(RM) $(MLX_TARGET)
	$(RM) $(LIBFT_TARGET)
	@make fclean -C $(LIBFT)

re: fclean all

$(NAME_BNS): $(LIBFT_TARGET) $(MLX_TARGET) $(GNL_OBJ) $(SL_OBJ_BNS) 
	$(CC) $(LIBFT_TARGET) $(CFLAGS) $(MLX_FLAGS) $(GNL_OBJ) $(SL_OBJ_BNS)  -o $(NAME_BNS)

bonus: $(NAME_BNS)

.PHONY:	all clean fclean re bonus