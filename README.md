# 42seoul Project list

1. [libft](#libft)
2. [get_next_line](#get_next_line)
3. [ft_printf](#ft_printf)

<br/><br/><br/><br/>

<a name="libft"></a>

# LIBFT

## 프로젝트 설명

<string.h> 의 함수들(strdup, atoi, ...)을 구현했으며 그 외에도 문자열을 다루는 편리한 함수들을 구현했습니다. 또한 linked-list를 다루기 위한 함수들도 구현했습니다. 이러한 편리한 기능을을 모두 구현하여 하나의 archive를 구성하는 프로젝트입니다.

## 제약조건

- 전역변수 사용 불가.
- 출력하는 경우 <unistd.h>의 `write`만 사용 가능.
- 메모리가 필요할 경우 <stdlib.h>의 `malloc`만 사용 가능.
- 절대 memory leak이 발생하면 안된다.

## Part 1 - Libc function

calloc과 strdup 는 malloc을 사용할 수 있으며 다른 함수들을 외부 함수를 사용하지 않는다.

1. isalpha
2. isdigit
3. isalnum
4. isascii
5. isprint
6. strlen
7. memset
8. bzero
9. memcpy
10. memmove
11. strlcpy
12. strlcat
13. toupper
14. tolower
15. strchr
16. strrchr
17. strncmp
18. memchr
19. memcmp
20. strnstr
21. atoi

## Part 2 - Additional functions

1. ft_substr

   문자열에서 특정 부분을 잘라 새로운 문자열을 생성하여 반환하는 함수.

2. ft_strjoin

   두 문자열을 이어붙여 새로운 문자열을 생성하여 반환하는 함수.

3. strtrim

   양 쪽 끝에서 지정한 문자들을 제거한 문자열을 생성하여 반환하는 함수.

4. ft_split

   구분자를 기준으로 문자열을 분할하여 그 결과를 문자열 배열에 저장하여 반환하는 함수.

5. ft_itoa

   인자로 받은 정수를 문자열로 변환하는 함수. 음수 또한 처리되어야 한다.

6. ft_strmapi

   문자열의 각 문자를 순회하여 인자로 받은 함수를 적용하고, 각 문자에 함수가 적용된 새로운 문자열을 생성하여 반환하는 함수.

7. ft_striteri

   문자열의 각 문자를 순회하여 인자로 받은 함수를 적용하는 함수.

8. ft_putchar_fd

   인자로 전달받은 file-descriptor에 문자를 출력한다.

9. ft_putstr_fd

   인자로 전달받은 file-descriptor에 문자열을 출력한다.

10. ft_putendl_fd

    인자로 전달받은 file-descriptor에 문자열을 출력하고, 개행을 출력한다.

11. ft_putnbr_fd

    인자로 전달받은 file-descriptor에 인자로 전달받은 정수를 출력한다.

## Part 3 - Linked list

Linked list를 사용할 때 필요한 함수들이다.

1. ft_lstnew
2. ft_lstadd_front
3. ft_lstsize
4. ft_lstlast
5. ft_lstadd_back
6. ft_lstdelone
7. ft_lstclear
8. ft_lstiter
9. ft_lstmap

<a name="get_next_line"></a>

# GET NEXT LINE

## 프로젝트 설명

## 제약조건

<a name="ft_printf"></a>

# FT PRINTF
