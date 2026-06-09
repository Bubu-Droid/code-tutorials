#include <iostream>
#include <string>

#include <stdlib.h> // the old string header file

// whenever we are going to use strings, we should always use const and then
// give it a reference so that the function does not create a local copy of the
// same string and waste memory
void PrintString(const std::string &string) {
  std::cout << string << std::endl;
}

int main() {
  // const char *name1 = "Bubu";
  // const wchar_t *name1 = L"Bubu"; // wide char
  // const char16_t *name1 = u"Bubu";
  // const char32_t *name1 = U"Bubu";
  // char name2[5] = {'B', 'u', 'b', 'u', '\0'};
  // 5 cuz we are also counting the \0 char
  // char name2[5] = {'B', 'u', 'b', 'u', 0};

  std::string name3 = "Avigyan";

  // std::cout << name1 << std::endl;
  // std::cout << name2 << std::endl;

  std::cout << name3 << std::endl;

  // strlen -- to print the length via stdlib.h

  PrintString(name3);

  std::string name0 =
      std::string("Bubu") + "hello"; // we gotta concatenate like this

  std::cout << name3.size() << std::endl;

  bool contains = name3.find("bu") != std::string::npos;

  using namespace std::string_literals; // this lets us append stuff to strings

  std::string name5 = "Bubu"s + "hello";      // we gotta concatenate like this
  std::wstring name6 = L"Bubu"s + L"hello";   // wide string (32 bits)
  std::u16string name7 = u"Bubu"s + u"hello"; // 16 bits string
  std::u32string name8 = U"Bubu"s + U"hello"; // 32 bits string

  std::string newname = R"(Line 1
Line 2
Line 3
Line 4)";

  newname = "mynewname";

  std::cout << newname << std::endl;

  //
  //
  //
  //
  //
  //
  //

  const int MAX_AGE = 90; // we are not going to modify this

  int x = 5, y = 6;

  const int *a = &x;
  // cannot change the values in *a, i.e., cannot do *a = ...
  int *const b = &y;
  // cannot change the values in b, i.e., cannot do b = &...

  // *a = 5;
  // b = &y;

  const int *const c = new int; // cannot change anything

  std::cin.get();
}

class Entity {
private:
  int m_X, m_Y;
  mutable int var;

public:
  int GetX() const { // the const here relays that you are not supposed to
                     // change values inside this function
    var = 2; // See how we can edit this even though the function has the const
             // keyword? This is because of the mutable keyword
    return m_X;
  }

  int GetX() {
    return m_X;
  } // when we comment out the GetX() function above, the e.GetX() below start
    // failing. Why is that you ask? Well, when we do not provide the const
    // keyword, we do not give any guarantee that we are not going to make
    // edits. Hence, if we are going to take the argument of the Entity as const
    // Entity &e, then we must make sure that functions like e.GetX() absolutely
    // do not tinker with the value associated with e. Hence, we need a const
    // only method for that purpose
  void SetX(int x) { m_X = x; }
};

void PrintEntity(const Entity &e) { // using const Entity here implies that we
                                    // are not going to edit the object here.
  // this assists us further by saving memory by not creating a copy of the
  // object for the function that we are working with
  // this is beneficial when we know we are only going to read the data and not
  // edit/write anything into it
  std::cout << e.GetX() << std::endl;
}

// const Entity *e -- we are not going to edit the value of *e, but we may edit
// the value of e

// const Entity &e -- we are not going to edit the value of e itself
