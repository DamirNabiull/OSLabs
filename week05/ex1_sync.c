#include <stdio.h>
#include <pthread.h>

void printThread(int n) {
    printf("Message from thread #%d\n", n);
}

int main(void) {
    int n = 5;
    pthread_t threads[n];
    for (int i = 0; i < n; i++) {
        printf("Thread #%d created\n", i+1);
        pthread_create(&threads[i], NULL, &printThread, i+1);
        pthread_join(threads[i], 0);
        printf("Thread #%d is done\n", i+1);
    }
}