#include <iostream>

enum Example : char { // the datatype can only be something related to int
  A = 65,
  B = 9,
  C = 66
};

int main() {
  Example var = A;
  // we cannot do something like Example var = 5; if we use the example keyword,
  // it must be taken from one of A, B, or C
  // However, at the end of the day, var is just a char too

  if (var == 'A') {
    std::cout << "Hello" << std::endl;
  } else if (var == 'B') {

    std::cout << "Bye!" << std::endl;
  }

  std::cin.get();
}
