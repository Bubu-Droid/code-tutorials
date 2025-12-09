#include <stdio.h>
#include <stdlib.h>

void reverse_array(int arr[], int n) {
  if (n == 1 || n == 0) {
    return;
  } else {
    int temp;
    temp = arr[0];
    arr[0] = arr[n - 1];
    arr[n - 1] = temp;
    reverse_array(arr + 1, n - 2);
  }
}

int main() {
  int n, i;
  printf("Enter the size of the array: ");
  scanf("%d", &n);
  int *arr = (int *)malloc(n * sizeof(int));
  printf("Enter the elements of the array separated by spaces:\n");
  for (i = 0; i < n; i++) {
    scanf("%d", &arr[i]);
  }
  reverse_array(arr, n);
  for (i = 0; i < n; i++) {
    printf("%d ", arr[i]);
  }
  return 0;
}
