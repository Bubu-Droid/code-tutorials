#include <algorithm>
#include <cstdint>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>
#include <utility>

class String {
private:
  char *m_Data;
  uint32_t m_Size;

public:
  String() = default;
  String(const char *string) {
    printf("Created!\n");
    m_Size = strlen(string);
    m_Data = new char[m_Size];
    memcpy(m_Data, string, m_Size);
  }
  String(const String &other) {
    printf("Copied!\n");
    m_Size = other.m_Size;
    m_Data = new char[m_Size];
    memcpy(m_Data, other.m_Data, m_Size);
  }
  String(String &&other) noexcept {
    printf("Moved!\n");
    m_Size = other.m_Size;
    m_Data = other.m_Data;

    other.m_Size = 0;
    other.m_Data = nullptr;
  }
  ~String() {
    printf("Destroyed!\n");
    delete m_Data;
  }

  void Print() {
    for (uint32_t i = 0; i < m_Size; i++) {
      printf("%c", m_Data[i]);
    }
    printf("\n");
  }
};

class Entity {
private:
  String m_Name;

public:
  Entity(const String &name) : m_Name(name) {}
  Entity(String &&name) : m_Name(std::move(name)) {}
  void PrintName() { m_Name.Print(); }
};

int main() {
  // I don't get the point of singletons, I prefer using namespaces for this
  // purpose.

  // Entity entity(String("Bubu"));
  // entity.PrintName();

  // String string = "Hello";
  // String dest = std::move(string);

  std::string meow = "meow";
  std::string neow;

  std::cout << "Meow: " << meow << std::endl;
  std::cout << "Neow: " << neow << std::endl;

  neow = std::move(meow);

  std::cout << "Meow: " << meow << std::endl;
  std::cout << "Neow: " << neow << std::endl;

  std::cin.get();
}
