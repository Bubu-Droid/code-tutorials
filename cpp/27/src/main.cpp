#include <chrono>
#include <iostream>
#include <thread>

static bool s_Finished = false;

void DoWork() {
  using namespace std::literals::chrono_literals;

  std::cout << "Started thread with id = " << std::this_thread::get_id()
            << std::endl;
  while (!s_Finished) {
    std::cout << "Working..." << std::endl;
    std::this_thread::sleep_for(1s);
  }
}

struct Timer {
  std::chrono::time_point<std::chrono::system_clock> start, end;
  std::chrono::duration<float> duration;
  Timer() { start = std::chrono::high_resolution_clock::now(); }
  ~Timer() {
    end = std::chrono::high_resolution_clock::now();
    duration = end - start;
    float ms = duration.count() * 1000.0f;

    std::cout << "Timer took " << ms << "ms" << std::endl;
  }
};

void Function() {
  Timer timer; // automatically gets destroyed when the scope ends and gives us
               // our benchmark metrics
  int i;
  for (int i = 0; i < 100; i++) {
    std::cout << i << std::endl; // removing endl has a huge improvement
  }
}

// this is very clean man
int main() {
  using namespace std::chrono_literals;
  std::cout << "Started thread with id = " << std::this_thread::get_id()
            << std::endl;

  std::thread worker(DoWork);

  std::cin.get();
  s_Finished = true;

  worker.join();

  std::cin.get();

  std::cout << "Finished thread with id = " << std::this_thread::get_id()
            << std::endl;

  //
  //
  //
  //
  //
  //
  //
  //
  //
  //
  //

  auto start = std::chrono::high_resolution_clock::now();
  std::this_thread::sleep_for(1s);
  auto end = std::chrono::high_resolution_clock::now();

  std::chrono::duration<float> duration = end - start;
  std::cout << duration.count() << "s" << std::endl;

  Function();
}
