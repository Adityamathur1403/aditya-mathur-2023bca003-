#include <stdio.h>

int binarySearchIterative(int arr[], int n, int target) {
	int left = 0;
	int right = n - 1;

	while (left <= right) {
		int mid = left + (right - left) / 2;

		if (arr[mid] == target) {
			return mid;
		} else if (arr[mid] < target) {
			left = mid + 1;
		} else {
			right = mid - 1;
		}
	}

	return -1;
}

int main() {
	int arr[] = {2, 5, 8, 12, 17, 23, 42};
	int n = sizeof(arr) / sizeof(arr[0]);
	int target = 17;

	int result = binarySearchIterative(arr, n, target);

	if (result != -1) {
		printf("Element %d found at index %d (using iterative binary search).\n", target, result);
	} else {
		printf("Element %d not found in the array.\n", target);
	}

	return 0;
}