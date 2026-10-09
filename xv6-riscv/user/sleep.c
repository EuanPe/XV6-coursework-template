#include "kernel/types.h" 
#include "user/user.h" 
int main(int argc, char *argv[]) {
	//Check ticks have been supplied
	if (argc < 2) {
		printf("Error: Please specify number of ticks \n");
		exit(0);
	}

	int ticks = atoi(argv[1]);
	pause(ticks);
	exit(0);
}
