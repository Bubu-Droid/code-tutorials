#include <stdio.h>

int dectobin(int n);

int main() {
  int n;
  printf("Enter the number: ");
  scanf("%d", &n);
  printf("The converted value is = %d", dectobin(n));
  return 0;
}

int dectobin(int n) {
  if (n == 0) {
    return 0;
  } else if (n == 1) {
    return 1;
  } else {
    return 10 * dectobin(n / 2) + (n % 2);
  }
}
