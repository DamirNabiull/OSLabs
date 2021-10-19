#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int n, ind = 0, ind_min = 0, page, j;
    unsigned short min;
    double hit = 0, miss = 0;
    char *str = malloc(256*sizeof(char));

    printf("Print number of pages: \n");
    fgets(str, 256, stdin);
    n = atoi(str);
    int pages[n];
    unsigned short bits[n];

    for (int i = 0; i < n; i++) {
        pages[i] = -1;
        bits[i] = 32768;
    }

    FILE* stream = fopen("input.txt", "r");
    while (fscanf(stream, "%s ", str) != EOF) {
        page = atoi(str);
        // printf("\n");

        for (int i = 0; i < ind; i++) {
            bits[i] = (bits[i] >> 1);
        }

        if (ind == n) {
            min = bits[0];
            ind_min = 0;
            j = ind;
            for (int i = 0; i < n; i++) {
                if (pages[i]==page) {
                    j = i;
                }
                if (bits[i] < min) {
                    min = bits[i];
                    ind_min = i;
                }
            }

            if (j == ind) {
                miss++;
                bits[ind_min] = 32768;
                pages[ind_min] = page;
            } else {
                hit++;
                bits[j] += 32768;
            }
        } else {
            j = ind;
            for (int i = 0; i < ind; i++) {
                if (pages[i]==page) {
                    j = i;
                    break;
                }
            }
            if (j == ind) {
                miss++;
                bits[ind] = 32768;
                pages[ind] = page;
                ind++;
            } else {
                hit++;
                bits[j] += 32768;
            }
        }

        for (int i = 0; i < n; i++) {
            printf("i = %d", i);
            if (pages[i] == -1) {
                printf(" id = -1 0\n");
            } else {
                printf(" id = %d %hu\n", pages[i], bits[i]);
            }
        }
        printf("Current page: %d\n\n", page);
    
    }
    double h_m = hit/miss;
    printf("hit: %f, miss: %f, H/M: %f", hit, miss, h_m);
}