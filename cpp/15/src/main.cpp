#include <iostream>
#include <string>

class Entity {
private:
  std::string m_Name;
  mutable int m_DebugCount = 0;

public:
  const std::string &GetName() const {
    m_DebugCount++;
    return m_Name;
  }
};

int main() {
  const Entity e; // we are making sure that we don't change e
  std::cout << e.GetName() << std::endl;
  std::cin.get();

  int x = 8;
  // = stands for passing by value and & stands for passing by reference
  // you can also use it as: auto f = [x]() ... or f = [&x]() ...
  auto f = [=]() mutable { // we do need the mutable keyword because otherwise,
                           // the x that is taken in sort of points back to the
                           // original x. when we use mutable, a new local
                           // variable y = x is created automatically
    x++;
    std::cout << x << std::endl;
  };
  f(); // x is still 8 after this
}
