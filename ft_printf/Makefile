CC		= gcc
NAME	= libftprintf.a
LIBFT	= libft
INCLUDE	= include
SRC_DIR	= src/
OBJ_DIR	= obj/
CFLAGS	= -Wall -Werror -Wextra
AR		= ar rcs

SRC_FILES	= ft_printf ft_print_ptr ft_print_hex ft_print_unsigned_int ft_print_nbr
SRC 		= $(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC_FILES)))
OBJ 		= $(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC_FILES)))

all: $(NAME)

$(NAME): $(OBJ_DIR) $(OBJ)
	make -C $(LIBFT)
	cp libft/libft.a $(NAME)
	$(AR) $(NAME) $(OBJ)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	$(CC) -I $(NAME) $(CFLAGS) -I $(INCLUDE) -I $(LIBFT) -c $< -o $@ 

$(OBJ_DIR):
	mkdir $(OBJ_DIR)

clean:
	rm -rf $(OBJ_DIR)
	make clean -C $(LIBFT)

fclean:	clean
	rm -f $(NAME)
	rm -f $(LIBFT)/libft.a

re: fclean all

.PHONY:	all clean fclean re libft