#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>

int main()
{
    char a[256];
    while (1) {
       fgets(a, 256, stdin);
       system(a);
    }
}
