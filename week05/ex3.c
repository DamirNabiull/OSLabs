#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

int N = 100000, count = 0;
int consumerWork = 0, producerWork = 0;

/*
    Race condition occur when consumer check value, it is equal 0 (Consumer works)
    Than works producer thread, and we increment count
    Now count == N and producer goes to sleep and wakeup consumer
    But consumer doesn't sleep
    Consumer stay in if condition and goes to sleep
    Now consumer and producer sleep forever
*/

void Producer() {
    while(1){
        if (count == N) {
            producerWork = 0;
            printf("Producer is sleeping\n");
            while(!producerWork) {}
        } else {
            count++;
            if (count == 1) {
                printf("Consumer started to work\n");
                consumerWork = 1;
            }
        }
    }
}

void Consumer() {
    while(1){
        if (count == 0) {
            consumerWork = 0;
            printf("Consumer is sleeping\n");
            while(!consumerWork) {}
        } else {
            count--;
            if (count == 0) {
                printf("Producer started to work\n");
                producerWork = 1;
            }
        }
    }
}

int main() {
    pthread_t *producer, *consumer;
    pthread_create(&producer, NULL, &Producer, NULL);
    pthread_create(&consumer, NULL, &Consumer, NULL);
    pthread_join(&consumer, 0);
    pthread_join(&producer, 0);
}