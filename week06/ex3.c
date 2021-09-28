#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int arr[10][3];

int queue[10], sizeQueue = 0;
int complete = 0, timeNow = 0, lastIndex = 0;

void addToQueue() {
    if (lastIndex < 10) {
        while (arr[lastIndex][0] == timeNow) {
            queue[sizeQueue++] = lastIndex;
            lastIndex++;
            if (lastIndex > 9) {
                break;
            }
        }
    }
}

void updateQueue() {
    if (arr[queue[0]][2] == 0) {
        arr[queue[0]][2] = timeNow;
        for (int i = 1; i < sizeQueue; i++) {
            queue[i-1] = queue[i];
        }
        sizeQueue--;
        complete++;
    } else {
        int t1 = queue[0];
        for (int i = 1; i < sizeQueue; i++) {
            queue[i-1] = queue[i];
        }
        queue[sizeQueue-1] = t1;
    }
}

void calculateCT(int ind, int quantum) {
    timeNow = arr[0][0];
    addToQueue();

    while (complete != ind){
        if (sizeQueue != 0) {
            int min = arr[queue[0]][2] < quantum ? arr[queue[0]][2] : quantum;
            for (int i = 0; i < min; i++) {
                timeNow++;
                addToQueue();
            }
            arr[queue[0]][2] = arr[queue[0]][2] < quantum ? 0 : arr[queue[0]][2] - quantum;
            updateQueue();
        } else {
            timeNow++;
            addToQueue();
        }
    }
}

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
    arr[num][2] = arr[num][1];
}

void sortRRA(int num) {
    int t1, t2, t3;
    for (int i = 0; i < num-1; i++) {
        for (int j = 0; j < num-i-1; j++) {
            if (arr[j][0] > arr[j+1][0]) {
                t1 = arr[j][0];
                t2 = arr[j][1];
                t3 = arr[j][2];

                arr[j][0] = arr[j+1][0];
                arr[j][1] = arr[j+1][1];
                arr[j][2] = arr[j+1][2];

                arr[j+1][0] = t1;
                arr[j+1][1] = t2;
                arr[j+1][2] = t3;
            }
        }
    }
}

int main(int argc, char **argv) {
// int main(void) {
    int quantum = atoi(argv[1]);
    // int quantum = 2;

    FILE* stream = fopen("input.csv", "r");

    int ind = 0;

    char line[256];
    while (fgets(line, 256, stream))
    {
        char* tmp = strdup(line);
        getfield(tmp, ind++);
        free(tmp);
    }

    sortRRA(ind);

    int ct = -1, tat = 0, wt = 0;
    double avrTurnaround = 0, avrWaiting = 0;
    
    calculateCT(ind, quantum);
        
    printf("P#\tAT\tBT\tCT\tTAT\tWT\n");

    for (int i = 0; i < ind; i++) {
        ct = arr[i][2];
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