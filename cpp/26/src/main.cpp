#include <algorithm>
#include <functional>
#include <iostream>
#include <vector>

void PrintValue(int value) { std::cout << "Value: " << value << std::endl; }

// void ForEach(const std::vector<int> &values, void (*func)(int)) {
void ForEach(const std::vector<int> &values,
             const std::function<void(int)> &func) {
  for (int value : values) {
    func(value);
  }
}

// NOTE: std::reverse(temp.begin(), temp.end()); // reverses the string

// never do using namespace std
// using namespace std makes a shorthand vector for std::vector and for other
// sub-functions too.
// WARNING: NEVER USE NAMESPACES IN HEADERS!!

namespace apple {
namespace functions {
void Print() { std::cout << "Apple" << std::endl; }
} // namespace functions
} // namespace apple

namespace orange {
void Print() { std::cout << "Orange" << std::endl; }
} // namespace orange

int main() {
  apple::functions::Print();
  orange::Print();

  // using namespace apple::functions; -- this allows us to use Print() directly
  // as shown below
  // Print();

  // using orange::Print; -- this allows us to use Print() function directly
  // (note that the entity at the end is a function and not a namespace!!!)
  // Print();

  namespace a = apple::functions; // this is an alias
  a::Print();

  // function pointer
  auto function = PrintValue;

  std::vector<int> vec = {1, 2, 3, 4, 5};

  ForEach(vec, function);

  // we can achieve the same using lambda functions
  // if you don't pass anything in the first square brackets, no variable from
  // The outer scope gets imported into the lambda function. Can pass multiple
  // things into lambda using [a, &b, ...], = -- everything by value, & --
  // everything by reference
  ForEach(vec, [](int value) { std::cout << value << std::endl; });

  auto it =
      std::find_if(vec.begin(), vec.end(), [](int value) { return value > 3; });

  std::cin.get();
}
