#include <iostream>

int main() {
  // std::cout << "Hello World!" << std::endl;
  for (int i = 0; i < 5; i++) {
    std::cout << i << std::endl;
  }

  int j = 0;
  for (; j < 6;) {
    std::cout << j << std::endl;
    j++;
  }
  // for (;;) {
  //   std::cout << j << std::endl;
  //   j++;
  // }

  while (j < 20) {
    if (j % 2 == 0) {
      j++;
      continue;
    } else {
      std::cout << "Nyan!" << std::endl;
    }
    j++;
  }

  do {
    std::cout << j << std::endl;
    if (j == 25) {
      break;
    }
    j++;
  } while (j < 30);

  std::cin.get();
}
