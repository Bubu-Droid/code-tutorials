#include <stdio.h>
#include <stdlib.h>

int binsearch(int arr[], int l, int u, int num) {
  if (l > u) {
    return -1;
  } else {
    int m = (l + u) / 2;
    if (arr[m] == num) {
      return m;
    } else if (arr[m] > num) {
      return binsearch(arr, l, m - 1, num);
    } else {
      return binsearch(arr, l + 1, u, num);
    }
  }
}

int main() {
  int n, i, num, res;
  printf("Enter the size of the array: ");
  scanf("%d", &n);
  int *arr = (int *)malloc(n * sizeof(int));
  printf("Enter the elements of the array separated by spaces:\n");
  for (i = 0; i < n; i++) {
    scanf("%d", &arr[i]);
  }
  printf("Enter the number you want to search: ");
  scanf("%d", &num);
  res = binsearch(arr, 0, n - 1, num);
  if (res != -1) {
    printf("The element was found at %d-th position!", res + 1);
  } else {
    printf("Element was not found!");
  }
}
