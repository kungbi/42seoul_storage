#include "get_next_line_bonus.h"

void leaks()
{
	system("leaks a.out");
}

int main()
{
	int		fd1;
	int		fd2;
	char	*result;

	fd1 = open("test2.txt", O_RDONLY);
	fd2 = open("test2.txt", O_RDONLY);
	result = get_next_line(fd1);
	printf("%s", result);
	result = get_next_line(fd2);
	printf("%s", result);
	result = get_next_line(fd1);
	printf("%s", result);
	result = get_next_line(fd2);
	printf("%s", result);
	result = get_next_line(fd2);
	printf("%s", result);
	result = get_next_line(fd2);
	printf("%s", result);
	result = get_next_line(fd2);
	printf("%s", result);
	result = get_next_line(fd2);
	printf("%s", result);
	result = get_next_line(fd1);
	printf("%s", result);
	result = get_next_line(fd1);
	printf("%s", result);
	result = get_next_line(fd1);
	printf("%s", result);
	result = get_next_line(fd1);
	printf("%s", result);
		// result = get_next_line(fd);
		// printf("%s", result);
	// result = get_next_line(fd);
	// printf("%s", result);
	// result = get_next_line(fd);
	// printf("%s", result);

	// atexit(&leaks);
	// fd = open("test.txt", O_RDONLY);
	// result = get_next_line(fd);
	// while (result != NULL)
	// {
	// 	printf("%s", result);
	// 	free(result);
	// 	result = get_next_line(fd);
	// }
	// free(result);
	return (0);
}

