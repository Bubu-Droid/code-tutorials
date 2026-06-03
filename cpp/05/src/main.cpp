#include <iostream>
#include <string>

void Increment(int *value) { (*value)++; }
void Decrement(int &value) { value--; }

int main() {
  int var = 8;
  // void *ptr = nullptr;
  // types do not matter, we need it to tell for writing values to it
  int *ptr = &var;
  std::cout << *ptr << std::endl;

  *ptr = 10;
  std::cout << *ptr << std::endl;

  char *buffer = new char[8];
  memset(buffer, 0, 8 * sizeof(char));

  char **pointer = &buffer;

  delete[] buffer;

  // These are references
  int num = 66;
  int &ref = num;
  ref = 2;

  std::cout << num << std::endl;

  Increment(&num);

  std::cout << num << std::endl;

  Decrement(num);

  std::cout << num << std::endl;

  int a = 9;
  int b = 10;

  // int &newref = a;
  // newref = b; // this changes the values of a to b

  int *newptr = &a;
  std::cout << *newptr << std::endl;

  newptr = &b;
  std::cout << *newptr << std::endl;

  std::cin.get();
}
