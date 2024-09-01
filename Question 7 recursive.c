#include <stdio.h>

int binarySearchRecursive(int arr[], int left, int right, int target) {
    if (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target) {
            return mid; 
        } else if (arr[mid] < target) {
            return binarySearchRecursive(arr, mid + 1, right, target);
        } else {
            return binarySearchRecursive(arr, left, mid - 1, target); 
    }

    return -1; 
}

int main() {
    int arr[] = {2, 5, 8, 12, 17, 23, 42}; 
    int n = sizeof(arr) / sizeof(arr[0]);
    int target = 17;

    int result = binarySearchRecursive(arr, 0, n - 1, target);

    if (result != -1) {
        printf("Element %d found at index %d (using recursive binary search).\n", target, result);
    } else {
        printf("Element %d not found in the array.\n", target);
    }

    return 0;
}