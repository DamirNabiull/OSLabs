#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>

int n;

int main() {
    if (fork() == 0) {
        printf("Hello from child [%d - %d]\n", getpid(), n);
    }
    else {
        printf("Hello from parent [%d - %d]\n", getpid(), n);
    }
}
