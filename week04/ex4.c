#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <string.h>

#define BUFFSIZE 256

void removeChar(char *str, char garbage) {
    char *src, *dst;
    for (src = dst = str; *src != '\0'; src++) {
        *dst = *src;
        if (*dst != garbage) dst++;
    }
    *dst = '\0';
}

int main() {
    printf("Use Ctrl+C to exit\n");
    while (1) {
        char *line, *split;
        char *commands[10];
        int ind = 0;

        line = malloc(256);
        fgets(line, BUFFSIZE, stdin);


        split = strtok(line, " ");
        while (split != NULL){
            commands[ind] = split;
            ind++;
            split = strtok(NULL, " ");
        }
        commands[ind] = NULL;

        if (commands[ind-1][strlen(commands[ind-1])-1] == '\n'){
            removeChar(commands[ind-1], '\n');
        }

        char *cmd = malloc(5 + strlen(commands[0]));
        strcat(cmd, "/bin/");
        strcat(cmd, commands[0]);

        int p[2];
        if (pipe(p) == -1)
            exit(1);

        int pid = fork();
        int is_background = 0;
        if (strcmp(commands[ind - 1], "&") == 0)
            is_background = 1;

        if (pid == 0) {
            close(p[0]);
            dup2(p[1], 1);
            dup2(p[1], 2);
            close(p[1]);
            execve(cmd, commands, NULL);
            exit(0);
        } else {
            if (is_background == 1) {
                close (p[1]);
                close(p[0]);
            } else {
                waitpid(pid, NULL, WUNTRACED);
                close(p[1]);

                char output[1024] = "";
                while (read(p[0], output, sizeof(output)) != 0)
                    printf("%s", output);

                if (output[strlen(output) - 1] != '\n')
                    printf("\n");
                close(p[0]);
            }
        }
    }
}
