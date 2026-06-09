#include "pch.h"

int main() {
  // use `g++ -std=c++14 pch.h` to compile the pre-compile header and then add
  // target_precompile_headers(30 PRIVATE "${source_dir}/pch.h") to the
  // CMakeLists.txt

  std::cout << "Hi" << std::endl;
  std::cin.get();
}
