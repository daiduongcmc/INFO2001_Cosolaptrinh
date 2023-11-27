#include <stdio.h>

int linearSearch(int arr[], int n, int x) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == x) {
            return i;
        }
    }
    return -1; 
}

int binarySearch(int arr[], int low, int high, int x) {
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == x) {
            return mid;
        } else if (arr[mid] < x) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return -1;
}

int main() {
    int arr[] = {2, 5, 8, 12, 16, 23, 38, 56, 72, 91};
    int n = sizeof(arr) / sizeof(arr[0]);
    int x = 23;
    int linearResult = linearSearch(arr, n, x);
    if (linearResult != -1) {
        printf("Tim thay gia tri %d tai chi so %d\n", x, linearResult);
    } else {
        printf("Khong tim thay gia tri %d \n", x);
    }

    int binaryResult = binarySearch(arr, 0, n - 1, x);
    if (binaryResult != -1) {
        printf("Tim thay gia tri %d tai chi so %d \n", x, binaryResult);
    } else {
        printf("Khong tim thay gia tri %d \n", x);
    }
    return 0;
}
