#include <stdio.h>

int linearSearch(int arr[], int size, int key) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == key)
            return i;
    }
    return -1;
}

int main() {
    int size, key;
    printf("Enter size of array: ");
    scanf("%d", &size);
    int arr[size];
    printf("Enter elements:\n");
    for (int i = 0; i < size; i++)
        scanf("%d", &arr[i]);
    printf("Enter element to search: ");
    scanf("%d", &key);

    int index = linearSearch(arr, size, key);
    if (index != -1)
        printf("Element found at index %d\n", index);
    else
        printf("Element not found\n");

    return 0;
}