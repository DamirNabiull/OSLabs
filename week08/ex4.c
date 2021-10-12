#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h> 
#include<sys/resource.h>

int main() {
    struct rusage usage;
    for (int i = 0; i < 15; i++) {
        char *arr = malloc(1024*1024*1024);
        memset(arr, '0', 1024*1024*1024);
        getrusage(RUSAGE_SELF, &usage);
   		printf("mem_usage: %ld\n",usage.ru_maxrss);
        sleep(1);
    }
	return 0;
}
