#include <iostream>

int main() {
  int var = 8;
  std::cout << var << std::endl;
  // std::cout << "Hello World!" << std::endl;
  // Some other values are:
  // char, short, long, long long, etc
  // We can also add unsigned before each of these
  // unsigned int newvar = 16;

  char newchar = 65;
  std::cout << newchar << std::endl; // this should print A

  // we need to mention the f at the end to ensure that it is a float
  float num = 5.5f;
  double newnum = 5.5;

  bool val = true;
  std::cout << val << std::endl; // this should print 1

  std::cout << sizeof(int) << std::endl;

  std::cin.get();
}
