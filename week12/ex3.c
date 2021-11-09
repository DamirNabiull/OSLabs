#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <linux/input.h>

char* button_value[2] = {"RELEASED", "PRESSED"};

int length_shortcuts[3] = {3, 2, 2};

int shortcut_cap[3] = {46, 30, 25};
int shortcut_pe[2] = {25, 18};
int shortcut_os[2] = {24, 31};

char* command_cap = "I passed the Exam!";
char* command_pe = "Get some cappuccino!";
char* command_os = "Operating Systems";

int main(){
	FILE* stream = fopen("/dev/input/by-path/platform-i8042-serio-0-event-kbd", "r");
	struct input_event input_key;
    int ind = 0, cur = 0, check = 0, but = 0;
    char* a_string = malloc(128);
    int line[256];

    int* shortcuts[3];
    shortcuts[0] = shortcut_cap; 
    shortcuts[1] = shortcut_pe; 
    shortcuts[2] = shortcut_os;

    char* commands[3];
    commands[0] = command_cap; 
    commands[1] = command_pe; 
    commands[2] = command_os;

    while (1) {
    	fread(&input_key, sizeof(struct input_event), 1, stream);
        if (input_key.type == 1) {
            snprintf(a_string, 128, "%u", input_key.code);
            but = atoi(a_string);
            if (input_key.value == 1) {
                printf("\n%s %#x %d\n", "PRESSED", input_key.code, input_key.code);
                line[ind] = but;
                ind = ind + 1;

                for (int i = 0; i < 3; i++) {
                    if (ind != length_shortcuts[i]) {
                        continue;
                    }
                    check = 0;
                    for (int j = 0; j < ind; j++) {
                        if (line[j]==shortcuts[i][j]) {
                            check++;
                        }
                    }
                    if (check == ind) {
                        printf("\n\n\t%s\n\n", commands[i]);
                    }
                }
            }
            else if (input_key.value == 0) {
                if (ind > 0) {
                    cur = 0;
                    for (int i = 1; i < ind; i++) {
                        if (line[i] == but) {
                            cur = i;
                            break;
                        }
                    }
                    for (int i = cur+1; i < ind; i++) {
                        line[i-1] = line[i];
                    }
                    ind = ind == 0 ? 0 : ind - 1;
                    printf("\n%s %#x %d\n", "RELEASED", input_key.code, input_key.code);
                }
                
            }
        }
    }
}