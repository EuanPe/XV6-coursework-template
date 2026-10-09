#include "kernel/types.h"
#include "user/user.h"

int main (int argc, char *argv[]) {
	printf("Uptime: %d ticks\n", uptime());
	exit(0);
}
