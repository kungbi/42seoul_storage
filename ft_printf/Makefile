CC		= gcc
NAME	= libftprintf.a
LIBFT	= libft
INCLUDE	= include
SRC_DIR	= src/
OBJ_DIR	= obj/
CFLAGS	= -Wall -Werror -Wextra
AR		= ar rcs

SRC_FILES	= ft_printf ft_putptr ft_puthex ft_put_unsigned_int
SRC 		= $(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC_FILES)))
OBJ 		= $(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC_FILES)))

OBJF		=	.cache_exists

all: $(NAME)

$(NAME): libft $(OBJ)
	$(AR) $(NAME) $(OBJ)

libft: 
	make -C $(LIBFT)
	cp libft/libft.a $(NAME)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c | $(OBJF)
	$(CC) -I $(NAME) $(CFLAGS) -I $(INCLUDE) -I $(LIBFT) -c $< -o $@ 

$(OBJF):
	@mkdir -p $(OBJ_DIR)

clean:
	rm -rf $(OBJ_DIR)
	make clean -C $(LIBFT)

fclean:	clean
	rm -f $(NAME)
	rm -f $(LIBFT)/libft.a

re: fclean all

.PHONY:	all clean fclean re libft