#include <stdio.h>
#include <stdlib.h>

void swap(int* a, int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    int a, b;
    char *str = malloc(256*sizeof(char));
    printf("First number:\n");
    fgets(str, 256, stdin);
    a = atoi(str);
    printf("Second number:\n");
    fgets(str, 256, stdin);
    b = atoi(str);
    swap(&a, &b);
    printf("After function: %d %d\n", a, b);
}
