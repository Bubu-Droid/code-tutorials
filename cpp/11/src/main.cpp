#include <iostream>

class Entity {
public:
  float X, Y;

  Entity() {
    X = 0.0f;
    Y = 0.0f;
  }

  void Move(int xa, int ya) {
    X += xa;
    Y += ya;
  }
};

class Player : public Entity {
public:
  const char *Name;
  void PrintName() { std::cout << Name << std::endl; }
  void PrintPos() { std::cout << X << ", " << Y << std::endl; }
};

int main() {
  Player player;
  player.Name = "Bubu";

  player.Move(5, 2);
  player.PrintPos();
  player.PrintName();
}
