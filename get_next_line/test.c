#include "get_next_line.h"

int main()
{
  int fd;
  char *result;
  
  fd = open("test.txt", O_RDONLY);
  result = get_next_line(fd);
  while (result != NULL)
  {
    printf("%s", result);
    free(result);
    result = get_next_line(fd);
  }
  free(result);
  // system("leaks a.out");
  return (0);
}