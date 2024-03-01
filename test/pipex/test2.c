#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

int main(int argc, char **argvv, char **env)
{
	char *argv[3];
	int infile_fd;
	int outfile_fd;

	infile_fd = open("infile", O_RDONLY);
	outfile_fd = open("outfile", O_WRONLY | O_CREAT | O_TRUNC, 0644);
	printf("outfile_fd: %d\n", outfile_fd);

	if (fork() == 0)
	{
		dup2(infile_fd, STDIN_FILENO);
		dup2(outfile_fd, STDOUT_FILENO);

		argv[0] = "cat";
		argv[1] = NULL;
		execve("/bin/cat", argv, NULL);
		exit(0);
	}

	wait(NULL);
	close(infile_fd);
	close(outfile_fd);
}