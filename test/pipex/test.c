#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

int main(int argc, char **argvv, char **env)
{
	int infile_fd;
	int outfile_fd;
	int fd[2];

	char *argv[3];

	infile_fd = open("infile", O_RDONLY);
	outfile_fd = open("outfile", O_WRONLY | O_CREAT | O_TRUNC, 0644);
	printf("outfile_fd: %d\n", outfile_fd);

	if (fork() == 0)
	{
		pipe(fd);
		if (fork() == 0)
		{
			close(fd[0]);
			dup2(infile_fd, STDIN_FILENO);
			// dup2(fd[1], STDOUT_FILENO);
			dup2(outfile_fd, STDOUT_FILENO);

			argv[0] = "ls";
			argv[1] = "-l";
			argv[2] = NULL;
			execve("/bin/ls", argv, NULL);

			close(fd[1]);
			exit(0);
		}

		// dup2(fd[0], STDIN_FILENO);
		// dup2(outfile_fd, STDOUT_FILENO);

		// argv[0] = "ls";
		// argv[1] = "-l";
		// argv[2] = NULL;
		// execve("/bin/ls", argv, NULL);

		// close(fd[1]);
		// close(fd[0]);
		// exit(0);
	}

	wait(NULL);
	wait(NULL);
	close(infile_fd);
	close(outfile_fd);
}