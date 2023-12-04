#include <stdio.h>
#include <stdlib.h>

int main() {
  int *arr;
  int size;
  printf("Nhap kich thuoc mang: ");
  scanf("%d", &size);
  arr = (int *)malloc(size * sizeof(int));
  for (int i = 0; i < size; i++) {
    arr[i] = i + 1;
  }
  for (int i = 0; i < size; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");
  free(arr);
  return 0;
}

