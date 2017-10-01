// https://stackoverflow.com/questions/2784500/how-to-send-a-simple-string-between-two-programs-using-pipes
// http://tldp.org/LDP/lpg/node11.html

#include <stdio.h>
#include <unistd.h> // pipe | man 3 pipe >> man 3 dup
#include <stdlib.h> // exit | man 3 exit
#include <string.h>

int main(void)
{
	int     fd[2], nbytes;
	pid_t   childpid;
	char    string[] = "Hello, world!\n";
	char    readbuffer[80];

	pipe(fd);

	if((childpid = fork()) == -1)
	{
		perror("fork");
		exit(1);
	}

	if(childpid == 0)
	{
		/* Child process closes up input side of pipe */
		close(fd[0]);

		/* Send "string" through the output side of pipe */
		write(fd[1], string, (strlen(string)+1));
		exit(0);
	}
	else
	{
		/* Parent process closes up output side of pipe */
		close(fd[1]);

		/* Read in a string from the pipe */
		nbytes = read(fd[0], readbuffer, sizeof(readbuffer));
		printf("Received string: %s", readbuffer);
	}

	return(0);
}
