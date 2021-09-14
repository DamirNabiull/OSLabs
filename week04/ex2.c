#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>

int main() {
    for (int i = 0; i < 5; i++) {
        fork();
	sleep(5);
    }
}
