#include <iostream>

class Entity {
public:
  float X, Y;

  // this is a constructor
  Entity() { // X = 0.0f;
    // Y = 0.0f;
    std::cout << "Constructed Entity!" << std::endl;
  }

  // this is also a constructor
  Entity(float x, float y) {
    X = x;
    Y = y;
  }

  // this is a destructor
  ~Entity() { std::cout << "Destructed Entity!" << std::endl; }

  void Print() { std::cout << X << ", " << Y << std::endl; }
};

class Log {
  // Every class has a constructor by default. If we wanna disable that, we have
  // to do it manually. This hides the constructor.

  // private:
  //   Log() {}

public:
  Log() = delete; // deleted the defualt constructor

  static void Print() {
    // this lowkey acts like a struct with a static Print() method
    std::cout << "Hello" << std::endl;
  }
};

int main() {
  // Entity e(10.0f, 5.5f);
  Entity e;
  e.Print();

  // Log l;
  // Log::Print();

  e.~Entity(); // this is used for manually executing the destructor
               // -- not recommended

  std::cin.get();
}
