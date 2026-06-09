#include <array>
#include <iostream>
#include <vector>

struct Vector3 {
  int x, y, z;
};

int main() {
  std::array<int, 4> arr = {1, 2, 3, 4}; // shorthand for allocation

  // we should try to always make vectors of objects and not pointers, but
  // making them of pointers makes them more optimized ig. but try not to do
  // that idk why, but Cherno said
  std::vector<int> intarr;
  intarr.push_back(4);

  std::vector<Vector3> vector;
  vector.push_back({1, 2, 3});
  vector.push_back({4, 5, 6});

  int i;

  for (i = 0; i < vector.size(); i++) {
    std::cout << vector[i].x << ", " << vector[i].y << ", " << vector[i].z
              << std::endl;
  }

  // this loop is cleaner but this actually makes a copy (since there is no &,
  // ALWAYS USE &!!!!!!! you aren't optimizing if there is no &!!!! LMFAO)
  for (Vector3 v : vector) {
    std::cout << v.x << ", " << v.y << ", " << v.z << std::endl;
  }

  // this makes a reference instead of needlessly copying the data
  for (Vector3 &v : vector) {
    std::cout << v.x << ", " << v.y << ", " << v.z << std::endl;
  }

  // vector.clear(); // resets the vector size to zero by deleting all elements

  // the .begin gives you the pointer to the first Vector3 object
  std::cout << vector.begin()->x << std::endl;

  // vector.erase(2); // can't do this
  vector.erase(vector.begin() + 1); // gotta do this to delete the second object

  std::cin.get();
}

// make sure you are using references for passing!!!!!!!!!!!!!!! OPTIMIZE!!!!!!
// LMAO
void Function(const std::vector<Vector3> &v) {}
