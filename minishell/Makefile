# 컴파일러와 플래그 설정
CC = gcc
# CFLAGS = -Wall -Wextra -Werror
LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

# 소스 파일 설정
SRC_FILES = $(shell find src -name "*.c")
OBJ_FILES = $(SRC_FILES:.c=.o)

# 타겟 설정
TARGET = minishell

# 기본 빌드 규칙
all: $(TARGET)

# 타겟 빌드 규칙
$(TARGET): $(OBJ_FILES) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJ_FILES) -o $@ -L $(LIBFT_DIR) -lft -lreadline

# 개별 파일 빌드 규칙
%.o: %.c
	$(CC) $(CFLAGS) -I src/header -c $< -o $@

# libft 빌드 규칙
$(LIBFT):
	@make -C $(LIBFT_DIR)

# 클린업 규칙
clean:
	rm -f $(OBJ_FILES)
	make -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(TARGET)
	make -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
