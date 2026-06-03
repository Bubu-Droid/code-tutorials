#include <iostream>
#include <string>

class Entity {
private:
  std::string m_Name;
  int m_Score;

public:
  Entity()
      : m_Name("Unknown"),
        m_Score(
            10) { // putting this inside the constructor instead of here results
                  // in multiple copies of the variable and thus wasting memory
  } // We need to make sure that the ordering of the initializers is identical
    // to that of their definition. This is crucial when we pass multiple
    // initializers!
  Entity(const std::string &name) : m_Name(name) {}

  void PrintName() { std::cout << m_Name << std::endl; }
};

int main() {
  Entity e0;
  e0.PrintName();

  Entity e1("Bubu");
  e1.PrintName();

  // var = condition ? value_if_true : value_if_false; // ternary operator

  // speed = (level > 5) ? (level > 10 ? 15 : 10) : 5;

  std::cin.get();
}
