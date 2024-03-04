#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

int main(int argc, char **argvv, char **env)
{
	int fd = open("outfile", O_CREAT | O_WRONLY | O_TRUNC, 0644);
	int a[2];
	char buf[100];

	pipe(a);
	if (fork() == 0)
	{
		printf("I am the child process with PID %d\n", getpid());
		if (fork() == 0)
		{
			printf("I am the child process with PID %d\n", getpid());
			if (fork() == 0)
			{
				if (fork() == 0)
				{
					close(a[0]);
					write(a[1], "hello\n", 100);
					printf("I am the child process with PID %d\n", getpid());
					exit(0);
				}
				read(a[0], buf, 100);
				printf("%s\n", buf);
				exit(0);
			}
			exit(0);
		}
		exit(0);
	}

	wait(NULL);
	wait(NULL);
	wait(NULL);
	wait(NULL);
}