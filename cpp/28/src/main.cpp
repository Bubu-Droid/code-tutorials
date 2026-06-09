#include <iostream>

int main() {
  const int arr_size_1 = 5;
  const int arr_size_2 = 6;
  const int arr_size_3 = 7;
  int i, j, k;

  int ***arr_1 = new int **[arr_size_1];

  for (i = 0; i < arr_size_1; i++) {
    arr_1[i] = new int *[arr_size_2];
  }

  for (i = 0; i < arr_size_1; i++) {
    for (j = 0; j < arr_size_2; j++) {
      arr_1[i][j] = new int[arr_size_3];
    }
  }

  for (i = 0; i < arr_size_1; i++) {
    for (j = 0; j < arr_size_2; j++) {
      for (k = 0; k < arr_size_3; k++) {
        arr_1[i][j][k] = i + j + k;
      }
    }
  }

  // for (i = 0; i < arr_size_1; i++) {
  //   for (j = 0; j < arr_size_2; j++) {
  //     for (k = 0; k < arr_size_3; k++) {
  //       std::cout << arr_1[i][j][k] << std::endl;
  //     }
  //   }
  // }

  // Note that this is pretty inefficient since we are storing the blocks of
  // memory at random places. It would be much better if the allocation were to
  // be contiguous. Let's do that.

  int *arr_new = new int[arr_size_1 * arr_size_2 * arr_size_3];

  for (i = 0; i < arr_size_1; i++) {
    for (j = 0; j < arr_size_2; j++) {
      for (k = 0; k < arr_size_3; k++) {
        arr_new[arr_size_2 * arr_size_3 * i + arr_size_3 * j + k] = i + j + k;
      }
    }
  }

  bool is_identical = true;

  for (i = 0; i < arr_size_1; i++) {
    for (j = 0; j < arr_size_2; j++) {
      for (k = 0; k < arr_size_3; k++) {
        if (arr_1[i][j][k] !=
            arr_new[arr_size_2 * arr_size_3 * i + arr_size_3 * j + k]) {
          is_identical = false;
        }
      }
    }
  }

  if (is_identical) {
    std::cout << "The arrays are identical!" << std::endl;
  }

  // Note that we have to manually free the memory too!

  for (i = 0; i < arr_size_1; i++) {
    for (j = 0; j < arr_size_2; j++) {
      delete[] arr_1[i][j];
    }
  }

  for (i = 0; i < arr_size_1; i++) {
    delete[] arr_1[i];
  }

  delete[] arr_1;

  delete[] arr_new;

  std::cin.get();
}
