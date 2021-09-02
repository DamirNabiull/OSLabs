#include <stdio.h>

void bubble_sort(int arr[], int n) {
    int temp;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

int main() {
    // Example of using bubble_sort()
    int arr[] = {534, 123, 4323, 543, 123, 543, 321, 646, 986, 509};
    int n = sizeof(arr)/sizeof(arr)[0];
    printf("Initial array: \n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n\n");

    bubble_sort(arr, n);

    printf("Array after sorting: \n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
