#include <iostream>

class Player {
public: // a class is private by default
  int x, y;
  int speed;

  void Move(int x_mag, int y_mag) {
    x = x_mag * speed;
    y = y_mag * speed;
  }
};

struct Goalie { // a struct is public by default
  int x, y;
  int speed;

  void Move(int x_mag, int y_mag) {
    x = x_mag * speed;
    y = y_mag * speed;
  }
};

// This is the only difference between a class and a struct
// Use structures for data and classes for more complex applications
// like using inheritance and all

int main() {
  Player player;
  player.x = 5;
  player.y = 0;
  player.speed = 1;

  std::cout << player.y << std::endl;

  player.Move(1, -1);

  std::cin.get();
}
