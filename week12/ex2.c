#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <linux/input.h>

char* button_value[2] = {"RELEASED", "PRESSED"};

int main(){
	FILE* stream = fopen("/dev/input/by-path/platform-i8042-serio-0-event-kbd", "r");
	struct input_event input_key;
    while (1) {
    	fread(&input_key, sizeof(struct input_event), 1, stream);
        if (input_key.type == 1) {
            printf("\n%s %#x %d\n", button_value[input_key.value], input_key.code, input_key.code);
        }
    }
}