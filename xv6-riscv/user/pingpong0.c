#include "kernel/types.h"
#include "user/user.h"

int main (void) {
	int pc[2]; //parent to child pipe
	int cp[2]; //child to perant pipe
	char byte;

	pipe(pc);
	pipe(cp);

	int pid = fork();

	if (pid == 0) {

		close(pc[1]);
		close(cp[0]);

		read(pc[0], &byte, 1);
		fprintf(1, "%d: received ping, %c\n", getpid(), byte);
		byte = 'R';

		write(cp[1], &byte, 1);

		close(pc[0]);
		close(cp[1]);
		exit(0);
	} else {
		close(pc[0]);
		close(cp[1]);

		byte = 'P';
		write(pc[1], &byte, 1);

		close(pc[1]);

		read(cp[0], &byte, 1);
		fprintf(1, "%d: received pong, %c\n", getpid(), byte);

		close(cp[0]);
		wait(0);
		exit(0);
	}
}
