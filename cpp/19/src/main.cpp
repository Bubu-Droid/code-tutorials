#include <iostream>

class Entity;

void PrintDetails(const Entity &e);

class Entity {
public:
  int x, y;
  Entity() { std::cout << "Created Entity!" << std::endl; }
  Entity(int x, int y) {
    this->x =
        x; // the "this" keyword is actually a pointer to the current object
    // if we access "this" in a non-const function (like the one we are in now),
    // then you may edit "this" and its associated values otherwise, if this
    // were a const function, you wouldn't be able to do so
    this->y = y;
  }

  void Print() {
    PrintDetails(*this);
  } // Note that since "this" is a pointer and we are taking in a reference to
    // the object for the function PrintDetails, we need to ensure that we pass
    // the object instead of the pointer. To avoid this, one may take in the
    // pointer itself in the PrintDetails function.
};

void PrintDetails(const Entity &e) {
  std::cout << e.x << ", " << e.y << std::endl;
}

int main() {
  Entity e(9, 10);
  e.Print();
  std::cin.get();
}
