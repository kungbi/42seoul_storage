#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

void leaks()
{
    system("leaks --list test");
}

int main(int argc, char **argvv, char **env)
{
	leaks();
    exit(0);
}