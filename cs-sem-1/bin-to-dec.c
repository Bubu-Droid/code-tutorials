#include <stdio.h>

int bintodec(int n);

int main() {
  int n;
  printf("Enter the number: ");
  scanf("%d", &n);
  printf("The converted value is = %d", bintodec(n));
  return 0;
}

int bintodec(int n) {
  if (n == 1 || n == 0) {
    return n;
  } else {
    return 2 * bintodec(n / 10) + (n % 10);
  }
}
