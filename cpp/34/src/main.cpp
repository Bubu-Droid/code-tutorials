#include <expected>
#include <format>
#include <iostream>
#include <print>
#include <string>

// the first datatype is the datatype of the result and the second one is for
// the type of the error (structs are mostly used for this)
std::expected<int, std::string> divide(int a, int b) {
  if (b == 0) {
    return std::unexpected("cannot divide by 0");
  }
  return a / b;
}

int main() {
  std::string string = std::format("Hello {} (AKA {})", "Avigyan", "Bubu");
  std::println("Hello {} (AKA {})", "Avigyan", "Bubu");
  std::print("No new line character at the end!");
  std::cout << string << std::endl;
  //
  //
  //
  //
  // we use transform instead of and_then if we know that we know something
  // won't go wrong
  auto result = divide(12, 0)
                    .and_then([](int result) { return divide(result, 2); })
                    .or_else([](const std::string &error) {
                      std::println("Error: {}", error);
                      return std::expected<int, std::string>{69};
                    });
  std::println("result = {}", *result);
  // std::cout << result.error();
}
