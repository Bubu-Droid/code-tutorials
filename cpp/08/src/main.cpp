#include <iostream>

struct Entity {
  // this makes the variables x and y global across all
  // objects initiated from this struct
  static int x, y;

  static void Print() { std::cout << x << ", " << y << std::endl; }
  // however, if we change the x and y variables to be non-static and keep the
  // Print method static, we would get an error since a static method cannot get
  // access to the non-static variables
};

// we need to initiate them because we are sort of making global variables
int Entity::x;
int Entity::y;

int main() {
  Entity e_1;
  Entity e_2;

  e_1.x = 2;
  e_1.y = 3;

  e_2.x = 5;
  e_2.y = 8;

  // this does the same job as above too and makes much more sense since it
  // stores the data inside the namespace rather than adding it to the same
  // namespace via an instance
  Entity::x = 6;
  Entity::y = 9;

  e_1.Print();
  e_2.Print();

  // this is in fact the "correct" way to call the static function inside the
  // struct/class
  Entity::Print();

  // these give the same output since we made the variables x and y static
  // inside the struct

  std::cin.get();
}
