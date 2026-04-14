#include <stdio.h>

int binarySearch(int arr[], int low, int high, int key) {
    if (low > high)
        return -1;
    int mid = (low + high) / 2;
    if (arr[mid] == key)
        return mid;
    else if (arr[mid] > key)
        return binarySearch(arr, low, mid - 1, key);
    else
        return binarySearch(arr, mid + 1, high, key);
}

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int size = sizeof(arr) / sizeof(arr[0]);
    int key = 6;
    int result = binarySearch(arr, 0, size - 1, key);
    if (result != -1)
        printf("Key found at index %d\n", result);
    else
        printf("Key not found\n");
    return 0;
}