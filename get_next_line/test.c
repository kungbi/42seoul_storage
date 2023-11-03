#include "get_next_line.h"

void leaks()
{
	system("leaks a.out");
}

int main()
{
	int		fd;
	char	*result;

	fd = open("test.txt", O_RDONLY);
	result = get_next_line(fd);
	printf("%s\n", result);
	result = get_next_line(fd);
	printf("%s\n", result);
	result = get_next_line(fd);
	printf("%s\n", result);
	result = get_next_line(fd);
	printf("%s\n", result);
	result = get_next_line(fd);
	printf("%s\n", result);
	result = get_next_line(fd);
	printf("%s\n", result);
	result = get_next_line(fd);
	printf("%s\n", result);
	result = get_next_line(fd);
	printf("%s\n", result);
	result = get_next_line(fd);
	printf("%s\n", result);
	// atexit(&leaks);
	// fd = open("test.txt", O_RDONLY);
	// result = get_next_line(fd);
	// while (result != NULL)
	// {
	// printf("%s", result);
	// free(result);
	// result = get_next_line(fd);
	// }
	// free(result);
	return (0);
}

