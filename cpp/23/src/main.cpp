#include <iostream>
#include <vector>

struct Vertex {
  float x, y, z;
  Vertex(float x, float y, float z) : x(x), y(y), z(z) {}
  // Vertex(const Vertex &v) : x(v.x), y(v.y), z(v.z) {
  //   std::cout << "Copied!" << std::endl;
  // }
};

void Function() {
  // suppose we make 5 Function() calls, then due to the static keyword, the int
  // i = 0; statement is not called multiple times. so, we get 1 2 3 4 5 as the
  // output. however, if we were to just use int i = 0; without the static
  // keyword, then we would've had 1 1 1 1 1 as the output. putting the
  // declaration int i = 0 outside the function definition would've the same
  // effect except that the variable i becomes public in that case which is not
  // good. the variable instance gets preserved throughout the program time.
  static int i = 0;
  i++;
  std::cout << i << std::endl;
}

class Singleton {
public:
  // the static keyword makes sure that the instance does not get deleted beyond
  // the scope of the curly braces below.
  static Singleton &Get() {
    static Singleton instance;
    return instance;
  }

  void Hello() {}
};

int main() {
  Singleton::Get().Hello();
  std::vector<Vertex> vertices;
  vertices.reserve(3);

  // std::vector<Vertex> vertices(3);
  //
  // we don't do this cuz this makes 3 vertices inside the vector vertices which
  // are initialized with the default constructor

  // This actually makes the vertex inside the main function and then copies it
  // to the vertices vector instead, what we'd like to do is to put the vector
  // inside vertices from the very beginning. To do that, we use emplace_back
  //
  // vertices.push_back({1, 2, 3});

  vertices.emplace_back(1, 2, 3);
  vertices.emplace_back(4, 5, 6);
  vertices.emplace_back(7, 8, 9);

  std::cin.get();
}
