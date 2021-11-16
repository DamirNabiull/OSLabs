#include <stdio.h>

#define RESOURCES_NUMBER 3
#define PROCESSES_NUMBER 5

int main(void) {
    FILE *fp;
    fp = fopen("input_ok.txt", "r");

    int E[RESOURCES_NUMBER];
    int A[RESOURCES_NUMBER];
    int C[PROCESSES_NUMBER][RESOURCES_NUMBER];
    int R[PROCESSES_NUMBER][RESOURCES_NUMBER];
    int released_processes[PROCESSES_NUMBER];
    int released = 0, found = 1, ok = 0;

    for (int i = 0; i < RESOURCES_NUMBER; i++) {
        fscanf(fp, "%d", &E[i]);
    }
    
    for (int i = 0; i < RESOURCES_NUMBER; i++) {
        fscanf(fp, "%d", &A[i]);
    }

    for (int i = 0; i < PROCESSES_NUMBER; i++) {
        released_processes[i] = 0;
        for (int j = 0; j < RESOURCES_NUMBER; j++) {
            fscanf(fp, "%d", &C[i][j]);
        }
    }
    
    
    for (int i = 0; i < PROCESSES_NUMBER; i++) {
        for (int j = 0; j < RESOURCES_NUMBER; j++) {
            fscanf(fp, "%d", &R[i][j]);
        }
    }

    while (released < PROCESSES_NUMBER && found) {
        found = 0;
        for (int i = 0; i < PROCESSES_NUMBER; i++) {
            if (released_processes[i] == 0) {
                ok = 1;
                for (int j = 0; j < RESOURCES_NUMBER; j++) {
                    if (R[i][j] > A[j]) {
                        ok = 0;
                        break;
                    }
                }
                if (ok) {
                    for (int j = 0; j < RESOURCES_NUMBER; j++) {
                        A[j] += C[i][j];
                        C[i][j] = 0;
                        R[i][j] = 0;
                    }
                    released++;
                    released_processes[i] = 1;
                    found = 1;
                }
            }
            else 
            {
                found = 0;
                continue;
            }
        }
    }

    if (released == PROCESSES_NUMBER) {
        printf("No deadlocks ʕ ᵔᴥᵔ ʔ");
    }
    else
    {
        for (int i = 0; i < PROCESSES_NUMBER; i++) {
            if (released_processes[i] == 0) {
                printf("Deadlock ( ͡° ͜ʖ ͡°)\nid: %d", i);
            }
        }
    }
}