#include <iostream>
#include <string>

class Entity {
public:
  int x = 5;
};

struct Vector3 {
  float x, y, z;
};

int main() {
  std::string a = "Bubu";
  std::string b = a;

  const char *moment = "hi";
  const char *newmoment = moment;

  std::cout << moment << std::endl;
  std::cout << newmoment << std::endl;

  b[0] = 'K';

  std::cout << &a << std::endl;
  std::cout << &b << std::endl;

  std::cout << a.size() << std::endl;
  // always use (const std::string &s) to pass the object by reference while
  // making functions
  //
  // a shallow copy copies the pointer or the reference to some data while the
  // deep copy copies the actual data residing inside the variable
  // when we are using the modern string functions, it makes a deep copy by
  // default. but if we want to make a shallow copy, then we need to copy via
  // reference. this is why we should use (const std::string &s) while passing
  // data to a function
  std::cout << &a << std::endl;
  std::cout << &b << std::endl;

  Entity e;
  Entity *ptr = &e;
  std::cout << ptr->x << std::endl; // we are using the arrow operator here

  //
  //
  //
  //
  //
  //
  //
  //
  //

  // Cherno uses int for this cuz he has a 32-bit application
  // dammnnnn, this is super coool!!!!
  long offset = (long)&((Vector3 *)nullptr)->z;
  std::cout << offset << std::endl;

  std::cin.get();
}
