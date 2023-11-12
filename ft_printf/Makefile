CC		= gcc
NAME	= libftprintf.a
LIBFT	= libft
INCLUDE	= include
SRC_DIR	= src/
OBJ_DIR	= obj/
CFLAGS	= -Wall -Werror -Wextra
AR		= ar rcs

#Sources
SRC_FILES	= ft_printf
SRC 		= $(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC_FILES)))
OBJ 		= $(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC_FILES)))

all: $(NAME)

$(NAME): libft $(OBJ)
	$(AR) $(NAME) $(OBJ)

libft: 
	make -C $(LIBFT)
	cp libft/libft.a .
	mv libft.a $(NAME)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	$(CC) $(NAME) $(CFLAGS) -I $(INCLUDE) -I $(LIBFT) -c $< -o $@ 

clean:
	rm -rf $(OBJ_DIR)
	make clean -C $(LIBFT)

fclean:	clean
	rm -f $(NAME)
	rm -f $(LIBFT)/libft.a

re: fclean all

.PHONY:	all clean fclean re libft