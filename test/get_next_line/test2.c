#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int main()
{
  int fd = open("example.txt", O_RDONLY);
  int fd2 = open("example2.txt", O_RDONLY);
  int fd3 = open("example3.txt", O_RDONLY);
  char *str;

  str = get_next_line(fd);
  printf("%s", str);
  str = get_next_line(fd2);
  printf("%s", str);
  str = get_next_line(fd3);
  printf("%s", str);
  str = get_next_line(fd);
  printf("%s", str);
  str = get_next_line(fd2);
  printf("%s", str);
  str = get_next_line(fd3);
  printf("%s", str);
}