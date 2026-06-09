#include <iostream>
#include <string>
#include <tuple>
#include <utility>

// One way to return different types of parameters is by using references. This
// is one of the best ways to do so since this is very memory efficient.
void func1(int in1, int &out1, float &out2) {
  out1 = in1;
  out2 = (float)in1;
}

// Another way to return different types if parameters is by using pointers.
// This is also great since you can check for null pointers here.
void func2(int in1, int *out1, float *out2) {
  if (out1) {
    *out1 = in1;
  }
  if (out2) {
    *out2 = (float)in1;
  }
}

// We may also use vectors/arrays to do the same task, but they end up
// allocating extra memory which just goes to waste.

// C++ also provides us one way of doing this, which is by making tuples.
std::tuple<std::string, int, int> func3() {
  return std::make_tuple("hi", 1, 2);
}

// If the number of return arguments is just 2, then we can use pair.
std::pair<std::string, int> func4() {
  return std::make_pair("avigyan chakraborty", 2);
}

// We may also use a struct to do the same thing which would then be much
// clearer. So, we can choose any one between this struct or the reference
// method to return data of different types from a function.
struct profile {
  std::string name;
  int age;
};

profile biodata() { return {"Bubu", 19}; }

int main() {
  int a = 6;
  float b = 6.0f;
  int c = 0;
  func1(c, a, b);

  std::cout << a << ", " << b << std::endl;

  int *e;
  e = nullptr;
  float *f = &b;
  *f = 6.0f;
  int g = 0;

  // In this case, e only gets returned if it is not a null pointer. Hence, this
  // idea may be used to exclude some returns like shaders when we want to
  // disable them in-game.
  func2(g, e, f);

  // std::tuple<std::string, int, int> res1 = func3();
  auto res1 = func3(); // the auto keyword auto-fills the type

  // We can also use using or typedef to do the same thing. `using` is the
  // modern way
  using Func1Type = std::tuple<std::string, int, int>;
  // Func1Type res1 = func3();

  std::pair<std::string, int> res2 = func4();

  std::cout << std::get<0>(res1) << ", " << std::get<1>(res1) << ", "
            << std::get<2>(res1) << std::endl;

  // this is the benefit of using pairs
  std::cout << res2.first << ", " << res2.second << std::endl;

  // This is the struct way to do this. Man this looks so much cleaner.
  profile bubuprof = biodata();
  std::cout << bubuprof.name << ", " << bubuprof.age << std::endl;

  std::cin.get();
}
