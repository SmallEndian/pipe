#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

int main(int argc, char ** argv){

	int pid = 0;

	if(argc < 2){
		printf("Usage: %s filename\n", argv[0]);
		exit(1);
	}

	pid = fork();

	if(pid){
		waitpid(pid, NULL, 0);

		printf("Use cat /tmp/is_pipe_working? \n");
		return 0;
	}

	// We replace the fd corresponding to stdout
	freopen("/tmp/is_pipe_working?", "w", stdout);
	execl(argv[1], NULL);

	return EXIT_SUCCESS;
}

