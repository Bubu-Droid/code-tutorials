#include <iostream>
#include <string>

class Entity {
private:
  std::string m_Name;
  int m_Age;

public:
  Entity(const std::string &name) : m_Name(name), m_Age(-1) {}
  // we give the explicit keyword to disable implicit conversion
  explicit Entity(int age) : m_Name("Unknown"), m_Age(age) {}
};

struct Vector2 {
  float x, y;

  Vector2(float x, float y) : x(x), y(y) {}

  Vector2 Add(const Vector2 &v) const { return Vector2(x + v.x, y + v.y); }
  Vector2 Multiply(const Vector2 &v) const { return Vector2(x * v.x, y * v.y); }

  // this is called operator overloading
  Vector2 operator+(const Vector2 &v) { return Add(v); }
  Vector2 operator*(const Vector2 &v) { return Multiply(v); }
  bool operator==(const Vector2 &v) { return (x == v.x) && (y == v.y); }
};

int main() {
  Entity a("Bubu");
  Entity b(19);

  // Entity c = 23; // implicit conversion

  Vector2 position(4.0f, 4.0f);
  Vector2 speed(0.5f, 1.5f);
  Vector2 powerup(1.1f, 1.1f);

  Vector2 result = position.Add(speed.Multiply(powerup));
  Vector2 newresult = position + (speed * powerup);

  std::cout << result.x << ", " << result.y << std::endl;
  std::cout << result.x << ", " << result.y << std::endl;

  if (result == newresult) {
    std::cout << "They both have the same vector values." << std::endl;
  }

  std::cout << 5 * 3 << std::endl;

  std::cin.get();
}
