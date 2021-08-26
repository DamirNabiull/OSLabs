#include <stdio.h>
#include <limits.h>
#include <float.h>

int main() {
    int intVariable = INT_MAX;
    float floatVariable = FLT_MAX;
    double doubleVariable = DBL_MAX;

    printf("Int:\nvalue:%d size:%lu\n", intVariable, sizeof(intVariable));
    printf("Float:\nvalue:%f size:%lu\n", floatVariable, sizeof(floatVariable));
    printf("Double:\nvalue:%f size:%lu\n", doubleVariable, sizeof(doubleVariable));

    return 0;
}
