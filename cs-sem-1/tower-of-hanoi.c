#include <stdio.h>

void toh(char a, char b, char c, int n, int *count);

int main() {
  int n, count;
  count = 0;
  printf("Enter the number of discs: ");
  scanf("%d", &n);
  toh('A', 'B', 'C', n, &count);
  printf("Number of moves needed = %d", count);
  return 0;
}

void toh(char a, char b, char c, int n, int *count) {
  if (n == 0) {
    return;
  } else {
    toh(a, c, b, n - 1, count);
    printf("Move disc from %c to %c\n", a, b);
    (*count)++;
    toh(c, b, a, n - 1, count);
  }
}
