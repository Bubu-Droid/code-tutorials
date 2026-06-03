#include <array>
#include <iostream>

int main() {
  int array[5];
  array[0] = 2;
  array[4] = 6;
  *(array + 2) = 3; // this is equal to array[2] using pointer arithmetic
  // *(int *)((char *)array + 8) = 3;
  // this actually does the same thing too! try parsing this in your mind

  // std::cout << array[0] << std::endl;
  // std::cout << array[4] << std::endl;
  // std::cout << array[1] << std::endl;
  // std::cout << array[2] << std::endl;
  // std::cout << array[3] << std::endl;

  int i;

  for (i = 1; i < 6; i++) {
    array[i - 1] = i;
  }

  for (i = 0; i < 5; i++) {
    std::cout << array[i] << std::endl;
  }

  std::cout << *array << std::endl;

  int ex1[5]; // this creates the array on the stack and the memory associated
              // with this is automatically cleared once the program ends
  // we do this when suppose we want to return an array from a function
  int *ex2 = new int[5]; // this creates the array on the heap and you need to
                         // manually de-allocate the memory -- if you forget to
                         // do so, you get a memory leak :))
  delete[] ex2;

  // we can do this only for stack allocated array and not for a heap allocated
  // array
  std::cout << sizeof(ex1) << std::endl; // gives the count of elements in it

  // old ways to use arrays
  static const int size = 5;
  int examplenew[size];

  // new way to use arrays
  std::array<int, 5> another;
  std::cout << another.size() << std::endl;

  std::cin.get();
}
