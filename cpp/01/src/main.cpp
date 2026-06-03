#include <iostream>

int Multiply(int a, int b) { return a * b; }
void MultiplyAndLog(int a, int b) { std::cout << a * b << std::endl; }

int main() {
  int result = Multiply(3, 2);
  std::cout << result << std::endl;

  MultiplyAndLog(40, 30);

  std::cin.get();
}
