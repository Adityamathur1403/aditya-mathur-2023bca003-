#include <stdio.h>

void deleteElement(int arr[], int *n, int position) {
    if (position < 0 || position >= *n) {
        printf("Invalid position. Cannot delete element.\n");
        return;
    }

    // Shift elements to the left
    for (int i = position; i < *n - 1; ++i) {
        arr[i] = arr[i + 1];
    }

    (*n)--;

    printf("Element at position %d deleted successfully.\n", position);
}

int main() {
    int arr[100] = {10, 25, 8, 17, 42}; 
    int n = 5; 
    int position = 2; 

    deleteElement(arr, &n, position);

    
    printf("Updated array: ");
    for (int i = 0; i < n; ++i) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}