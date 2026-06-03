#include <iostream>
#include <memory>
#include <string>

class Entity {
public:
  Entity() { std::cout << "Created Entity!" << std::endl; }
  ~Entity() { std::cout << "Destroyed Entity!" << std::endl; }
  void Print() const { std::cout << "Printing!" << std::endl; }
};

int main() {
  {
    // Entity e;
    std::unique_ptr<Entity> e = std::make_unique<Entity>();
    e->Print();
    std::cin.get();
  }
  {
    // std::shared_ptr<Entity> e0;
    std::weak_ptr<Entity> e1;
    {
      std::shared_ptr<Entity> sharedEntity =
          std::make_shared<Entity>(); // increases ref count for each copy
      // e0 = sharedEntity;
      e1 = sharedEntity; // this gets deleted as soon as we leave this scope
                         // since the weak pointer does not increase the ref
                         // count
      std::cin.get();
    }
    std::cin.get();
  }
  std::cin.get();
}
