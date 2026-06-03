#include <iostream>

class Printable {
  // public -- can be accessed from anywhere
  // protected -- can only be accessed from its sub-classes
  // private -- can only be accessed from within its own class
public:
  virtual std::string GetClassName() = 0;
};

class Entity : public Printable {
public:
  // the virtual allows overriding the function
  // virtual std::string GetName() { return "Entity"; }
  std::string GetClassName() override { return "Entity"; }
};

class Player : public Entity {
private:
  std::string m_Name;

public:
  Player(const std::string &name) : m_Name(name) {}
  std::string GetClassName() override { return m_Name; }
  // std::string GetName() override { return m_Name; }
  // using the override is not compulsorily needed, but you should always
  // include them if you're overriding a function
};

// void PrintName(Entity *entity) { std::cout << entity->GetName() << std::endl;
// }

void Print(Printable *obj) { std::cout << obj->GetClassName() << std::endl; }

int main() {
  Entity *e = new Entity();
  // PrintName(e);
  Print(e);

  Player *p = new Player("Cherno");
  // PrintName(p);
  Print(p);

  std::cin.get();
}
