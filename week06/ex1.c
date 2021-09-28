#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int arr[10][2];

void getfield(char* line, int num)
{
    char **s = malloc(2*sizeof(char*));
    s[0] = malloc(256*sizeof(char));
    s[1] = malloc(256*sizeof(char));
	int n = strlen(line), k = 0, j = 0;
    for (int i = 0; i < n; i++) {
        if (line[i] != ',' && line[i] != '\n') {
            s[k][i-j] = line[i];
        } else {
            k++;
            j = i+1;
        }
    }
    arr[num][0] = atoi(s[0]);
    arr[num][1] = atoi(s[1]);
}

void sortFCFS(int num) {
    int t1, t2;
    for (int i = 0; i < num-1; i++) {
        for (int j = 0; j < num-i-1; j++) {
            if (arr[j][0] > arr[j+1][0]) {
                t1 = arr[j][0];
                t2 = arr[j][1];

                arr[j][0] = arr[j+1][0];
                arr[j][1] = arr[j+1][1];

                arr[j+1][0] = t1;
                arr[j+1][1] = t2;
            }
        }
    }
}

int main(void) {
    FILE* stream = fopen("input.csv", "r");

    int ind = 0;

    char line[256];
    while (fgets(line, 256, stream))
    {
        char* tmp = strdup(line);
        getfield(tmp, ind++);
        free(tmp);
    }

    sortFCFS(ind);

    int ct = -1, tat = 0, wt = 0;
    double avrTurnaround = 0, avrWaiting = 0;

    printf("P#\tAT\tBT\tCT\tTAT\tWT\n");

    for (int i = 0; i < ind; i++) {
        if (ct == -1) {
            ct = arr[i][0] + arr[i][1];
        } else {
            ct = ct < arr[i][0] ? arr[i][0] + arr[i][1] : ct+arr[i][1];
        }
        tat = ct-arr[i][0];
        wt = tat - arr[i][1];
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n", i+1, arr[i][0], arr[i][1], ct, tat, wt);

        avrTurnaround += tat;
        avrWaiting += wt;
    }

    avrWaiting/=ind;
    avrTurnaround/=ind;

    printf("\nAverage Turnaround: %f \n", avrTurnaround);
    printf("Average Waiting: %f \n", avrWaiting);
}