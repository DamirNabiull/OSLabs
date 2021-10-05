#include <stdio.h>
#include <stdlib.h>

int main(void) {
    printf("Print number n:\n");
    char *str = malloc(256*sizeof(char));
    fgets(str, 256, stdin);
    int n = atoi(str);
    int* arr = malloc(n * sizeof(int));

    for (int i = 0; i < n; i++) {
        arr[i] = i;
    }

    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    free(arr);
    free(str);
}