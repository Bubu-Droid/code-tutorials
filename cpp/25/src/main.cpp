#include <array>
#include <iostream>
#include <string>

// Let's print an array
template <int length> void PrintArray(const std::array<int, length> &array) {
  int i;
  for (i = 0; i < array.size(); i++) {
    std::cout << array[i] << std::endl;
  }
}

// this is a macro
#define WAIT std::cin.get()
#define CLOSE_CURLY }

// DAMNNN!! THIS IS SUPER COOL!!
#define DEBUG 1
// #define RELEASE 1

#if DEBUG == 1
// macro with parameter
#define Log(x) std::cout << x << std::endl
#elif defined(RELEASE)
#define Log(x) std::cout << "In RELEASE mode" << std::endl
#else
// removes the text all together
#define Log(x)
#endif

template <typename T> void Print(T value) { std::cout << value << std::endl; }

template <typename T, int N> class Array {
private:
  std::array<T, N> arr;

public:
  int GetSize() { return arr.size(); }
};

int main() {
  Print(5);
  Print<float>(5.0f);
  Print("meow");

  WAIT;

  Array<std::string, 5> arr;
  // std::cout << arr.GetSize() << std::endl;
  Log(arr.GetSize());

#if 0
  std::cout << "I wanna make this line removable using macros!" << std::endl;
#endif

  std::cin.get();

  //
  //
  //
  //
  //
  //

  // this is INSANELY cute uwuuuuuuu!!!!
  std::array<int, 9> array = {1, 2, 3, 4, 5, 6, 7, 8, 9};
  PrintArray<array.size()>(array);

  // CLOSE_CURLY
}
