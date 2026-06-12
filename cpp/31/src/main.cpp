#include <any>
#include <fstream>
#include <iostream>
#include <optional>
#include <string>
#include <string_view>
#include <variant>

std::optional<std::string> ReadFileAsString(const std::string &filepath) {
  std::ifstream stream(filepath);
  if (stream) {
    std::string result;
    // read the file
    stream.close();
    return result;
  }

  // otherwise return an empty std::optional
  return {};
}

int main() {
  std::optional<std::string> data = ReadFileAsString("data.txt");

  std::string value = data.value_or("Not present!");

  std::cout << value << std::endl;

  if (data) {
    std::cout << "File read successfully!" << std::endl;
  } else {
    std::cout << "File couldn't be accessed!" << std::endl;
  }
  std::cin.get();

  //
  //
  //
  //

  std::variant<std::string, int> newdat;
  newdat = "bubu";
  newdat.index();
  // this tell us which index the data is being stored in
  // for this case, it returns 0 as the datatype is string
  newdat = 1;
  newdat.index();
  // for this case, it returns 1 as the datatype is int

  // this gets the string value from newdat, given that the type is string and
  // otherwise throws an error (probably)
  std::get<std::string>(newdat);

  // this returns nullptr if the data is not of the mentioned type and otherwise
  // returns the pointer to the string
  if (auto newval = std::get_if<std::string>(&newdat)) {
    std::string &v = *newval;
  } else {
    // ...
  }
}

enum ErrorCode { NoError = 0, NotFound = 1 };

std::variant<std::string, ErrorCode> ReadFileAsStringNew() {
  if (1) {
    return "file read successfully!";
  } else {
    return NotFound;
  }

  //
  //
  //
  //

  // I don't like this
  std::any data;
  data = 2;
  data = "Bubu";
  // std::string("Bubu");
  std::string &string = std::any_cast<std::string &>(data);

  //
  //
  //
  //

  std::string name = "Yan Chernikov";
  std::cout << name.substr(0, 3) << std::endl;
  // string allocations are slow
  // every time you use substr, it makes a new string. instead of that, we use a
  // string_view
  // this makes no allocations
  std::string_view first_name(name.c_str(), 3);
  std::string_view last_name(name.c_str() + 4, 9);
}
