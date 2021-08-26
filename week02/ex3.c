#include <stdio.h>
#include <stdlib.h>

void func0(int n) {
    int len = n*2-1;
    char *ans = malloc(len*sizeof(char));
    int l = (len)/2, r = (len)/2;
    for (int i = 0; i < len; i++) {
        ans[i] = ' ';
    }
    for (int i = 0; i < n; i++) {
        ans[l] = '*';
        ans[r] = '*';
        l--;
        r++;
        printf("%s\n", ans);
    }
}

void func1(int n) {
    char *ans = malloc(n*sizeof(char));
    for (int i = 0; i < n; i++) {
        ans[i] = ' ';
    }
    for (int i = 0; i < n; i++) {
        ans[i] = '*';
        printf("%s\n", ans);
    }
}

void func2(int n) {
    int len = n/2 + n%2;
    char *ans = malloc(len*sizeof(char));
    for (int i = 0; i < len; i++) {
        ans[i] = ' ';
    }
    for (int i = 0; i < n/2; i++) {
        ans[i] = '*';
        printf("%s\n", ans);
    }
    ans[len-1] = '*';
    printf("%s\n", ans);
    for (int i = 0; i < n/2; i++) {
        ans[len-i-1] = ' ';
        printf("%s\n", ans);
    }
}

void func3(int n) {
    char *ans = malloc(n*sizeof(char));
    for (int i = 0; i < n; i++) {
        ans[i] = '*';
    }
    for (int i = 0; i < n; i++) {
        printf("%s\n", ans);
    }
}

int main() {
    int n, m;
    printf("Print number n:\n");
    char *str = malloc(256*sizeof(char));
    fgets(str, 256, stdin);
    n = atoi(str);
    func0(n);
    printf("Choose another function: print \'1\', \'2\' or \'3\' \n*(All number = number of picture in task)\n");
    fgets(str, 256, stdin);
    m = atoi(str);
    if (m == 1) {
        func1(n);
    }
    else if (m == 2) {
        func2(n);
    }
    else if (m == 3) {
        func3(n);
    }
    else {
        printf("No such function exist");
    }
}
