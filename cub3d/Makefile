# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: woonshin <woonshin@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/25 13:38:46 by woonshin          #+#    #+#              #
#    Updated: 2024/10/27 23:48:50 by woonshin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Color Definitions
GREEN  = \033[1;32m
RED    = \033[1;31m
BLUE   = \033[1;34m
RESET  = \033[0m

CC				= cc
NAME			= cub3D
CFLAGS			= -Wall -Werror -Wextra

SRC_FILES = $(shell find src -name "*.c")
OBJ_FILES = $(SRC_FILES:.c=.o)

LIBFT_DIR		= libft
LIBFT_TARGET	= $(LIBFT_DIR)/libft.a

INCLUDES		=  -I src/header -I $(LIBFT_DIR) -I mlx

MLX_DIR			= mlx
MLX_TARGET		= $(MLX_DIR)/libmlx.a
MLX_FLAGS		= -Lmlx -lmlx -framework OpenGL -framework AppKit

all: $(NAME)

$(NAME): $(OBJ_FILES) $(LIBFT_TARGET) $(MLX_TARGET)
	@echo "$(BLUE)Building $(NAME)...$(RESET)"
	@$(CC) $(CFLAGS) $(MLX_FLAGS) $(LIBFT_TARGET) $(OBJ_FILES) -o $(NAME)
	@echo "$(GREEN)Build complete!$(RESET)"

%.o : %.c
	@echo "$(BLUE)Compiling $<...$(RESET)"
	@$(CC) $(CFLAGS) $(INCLUDES) -c -o $@ $<
	@echo "$(GREEN)Compiled: $<$(RESET)"

$(LIBFT_TARGET):
	@echo "$(BLUE)Building libft...$(RESET)"
	@make -C $(LIBFT_DIR)

$(MLX_TARGET):
	@echo "$(BLUE)Building mlx...$(RESET)"
	@make -C $(MLX_DIR)

clean:
	@echo "$(RED)Cleaning object files...$(RESET)"
	@$(RM) -f $(OBJ_FILES)
	@-make -C $(LIBFT_DIR) clean
	@-make -C $(MLX_DIR) clean
	@echo "$(GREEN)Clean complete!$(RESET)"

fclean: clean
	@echo "$(RED)Cleaning all...$(RESET)"
	@$(RM) -f $(NAME)
	@$(RM) $(MLX_TARGET)
	@-make -C $(LIBFT_DIR) fclean
	@echo "$(GREEN)Full clean complete!$(RESET)"

re: fclean all

.PHONY:	all clean fclean re
