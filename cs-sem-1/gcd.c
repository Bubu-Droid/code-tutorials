#include <stdio.h>

int gcd(int a, int b);

int main() {
  int a, b;
  printf("Enter the first number: ");
  scanf("%d", &a);
  printf("Enter the second number: ");
  scanf("%d", &b);
  printf("GCD of %d and %d is = %d", a, b, gcd(a, b));
  return 0;
}

int gcd(int a, int b) {
  if (b == 0) {
    return a;
  } else {
    if (b >= a) {
      return gcd(a, b - a * (b / a));
    } else {
      return gcd(b, a - b * (a / b));
    }
  }
}
