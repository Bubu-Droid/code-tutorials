#include <algorithm>
#include <iostream>
#include <vector>

class Base {
public:
  Base() { std::cout << "Base Constructor" << std::endl; }
  virtual ~Base() { std::cout << "Base Destructor" << std::endl; }
};

class Derived : public Base {
private:
  int *m_Array;

public:
  Derived() {
    m_Array = new int[5];
    std::cout << "Derived Constructor" << std::endl;
  }
  ~Derived() {
    delete[] m_Array;
    std::cout << "Derived Destructor" << std::endl;
  }
};

int main() {
  std::vector<int> vec = {2, 4, 3, 5, 1};
  // std::sort(vec.begin(), vec.end()); // sorts in ascending order by default
  std::sort(vec.begin(), vec.end(), [](int a, int b) {
    if (a == 1) {
      return false;
    } else if (b == 1) {
      return true; // returning true means you put a before b and vice-versa
    } else {
      return a < b;
    }
  });
  for (int value : vec) {
    std::cout << value << std::endl;
  }
  //
  //
  //
  //
  //
  //
  Derived *derived = new Derived();
  delete derived;
  std::cout << "------------------" << std::endl;

  Base *poly = new Derived();
  delete poly; // this also calls the derived destructor since we are using a
               // virtual destructor

  //
  //
  //
  //
  // C style casts
  double a = 9.5;
  int b = a;      // implicit casting
  int c = (int)a; // explicit casting

  // C++ style cast
  int d = static_cast<int>(a);
  // I don't like the idea of dynamic casting. I don't think I'm gonna ever
  // gonna need it. So no docs for it.

  std::cout << b << ", " << c << ", " << d << std::endl;

  std::cin.get();
}
