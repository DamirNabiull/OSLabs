#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h> 

int main() {
    for (int i = 0; i < 15; i++) {
        char *arr = malloc(1024*1024*1024);
        memset(arr, '0', 1024*1024*1024);
        sleep(1);
    }
	return 0;
}