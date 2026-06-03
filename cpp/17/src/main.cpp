#include <iostream>
#include <string>

class Entity {
private:
  std::string m_Name;

public:
  Entity() : m_Name("Unkown") {};
  Entity(const std::string &name) : m_Name(name) {}

  const std::string &GetName() const {
    return m_Name;
  } // understand this correctly, this is very important
};

int main() {
  Entity *e;
  {
    Entity *e0 = new Entity("Avigyan");
    e = e0;
  }

  // std::cout << (*e).GetName() << std::endl;
  std::cout << e->GetName() << std::endl;

  Entity e1("Bubu");
  std::cout << e1.GetName() << std::endl;

  std::cin.get();

  delete e;

  Entity *e3 = new Entity[50]; // new also calls the defualt constructor for
                               // each of the Entities that are created
  delete[] e3;                 // delete also calls the destructor
}
