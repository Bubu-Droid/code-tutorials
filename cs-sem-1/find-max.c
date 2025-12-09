#include <stdio.h>
#include <stdlib.h>

float find_max(float arr[], int n);

int main() {
  int n, i;
  printf("Enter the size of the array: ");
  scanf("%d", &n);
  float *arr = (float *)malloc(n * sizeof(float));
  for (i = 0; i < n; i++) {
    printf("Enter the %d-th number: ", i + 1);
    scanf("%f", &arr[i]);
  }
  printf("The maximum element from the array is = %f", find_max(arr, n));
  return 0;
}

float find_max(float arr[], int n) {
  if (n == 1) {
    return arr[0];
  } else if (arr[0] > find_max(arr + 1, n - 1)) {
    return arr[0];
  } else {
    return find_max(arr + 1, n - 1);
  }
}
