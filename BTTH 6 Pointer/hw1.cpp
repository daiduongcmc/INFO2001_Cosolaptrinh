#include <stdio.h>

void inputArray(int *arr, int size) {
  for (int i = 0; i < size; i++) {
    printf("Nhap phan tu thu %d: ", i + 1);
    scanf("%d", &arr[i]);
  }
}

void printArray(int *arr, int size) {
  for (int i = 0; i < size; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");
}

int findElement(int *arr, int size, int element) {
  for (int i = 0; i < size; i++) {
    if (arr[i] == element) {
      return i;
    }
  }
  return -1;
}

int main() {
  int arr[100];
  int size;

  printf("Nhap kich thuo cua mang: ");
  scanf("%d", &size);

  inputArray(arr, size);
  printArray(arr, size);

  int element;
  printf("Nhap phan tu can tim: ");
  scanf("%d", &element);

  int index = findElement(arr, size, element);
  if (index >= 0) {
    printf("Phan tu %d nam o vi tri thu %d trong mang.\n", element, index + 1);
  } else {
    printf("Khong tim thay phan tu %d trong mang.\n", element);
  }

  return 0;
}

