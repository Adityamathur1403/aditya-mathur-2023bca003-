#include <stdio.h>

void mergeArrays(int arr1[], int n1, int arr2[], int n2, int mergedArr[]) {
    int i, j, k;
    i = j = k = 0;

    while (i < n1 && j < n2) {
        if (arr1[i] < arr2[j]) {
            mergedArr[k++] = arr1[i++];
        } else {
            mergedArr[k++] = arr2[j++];
        }
    }

    while (i < n1) {
        mergedArr[k++] = arr1[i++];
    }

    while (j < n2) {
        mergedArr[k++] = arr2[j++];
    }
}

int main() {
    int arr1[] = {10, 25, 8};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);

    int arr2[] = {17, 42, 5};
    int n2 = sizeof(arr2) / sizeof(arr2[0]);

    int mergedArr[100]; 

    mergeArrays(arr1, n1, arr2, n2, mergedArr);

    printf("Merged array: ");
    for (int i = 0; i < n1 + n2; ++i) {
        printf("%d ", mergedArr[i]);
    }
    printf("\n");

    return 0;
}