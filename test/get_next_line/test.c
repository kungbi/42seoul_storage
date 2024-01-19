#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int main()
{
  int fd = open("example.txt", O_RDONLY);
  char *str;

  str = get_next_line(fd);
  while (str)
  {
    printf("%s", str);
    str = get_next_line(fd);
  }
}