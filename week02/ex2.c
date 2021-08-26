#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    char *str = malloc(256*sizeof(char)), temp;
    printf("Print your string\n");
    fgets(str, 256, stdin);
    unsigned long len = strlen(str);
    for (int i = 0; i < len/2; i++) {
        temp = str[i];
        str[i] = str[len-1-i];
        str[len-1-i] = temp;
    }
    printf("Inverted: %s", str);
}
