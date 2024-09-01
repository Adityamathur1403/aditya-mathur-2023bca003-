#include <stdio.h>
void insertElement(int arr[], int *n, int position, int element) {
    if (position < 0 || position > *n) {
        printf("Invalid position. Cannot insert element.\n");
        return;
    }

    for (int i = *n; i > position; --i) {
        arr[i] = arr[i - 1];
    }

    arr[position] = element;
    (*n)++; 

    printf("Element %d inserted at position %d.\n", element, position);
}

int main() {
    int arr[100] = {10, 25, 8, 17, 42}; 
    int n = 5; 
    int position = 2; 
    int element = 15; 

    insertElement(arr, &n, position, element);


    printf("Updated array: ");
    for (int i = 0; i < n; ++i) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}