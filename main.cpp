#include "day7.h"

#include <chrono>
#include <iostream>

using namespace day7;

int main() {
  using std::chrono::duration;
  using std::chrono::duration_cast;
  using std::chrono::high_resolution_clock;
  using std::chrono::milliseconds;

  try {
    auto t1 = high_resolution_clock::now();
    part1();
    auto t2 = high_resolution_clock::now();
    part2();
    auto t3 = high_resolution_clock::now();

    auto part1Bench = duration_cast<milliseconds>(t2 - t1);
    auto part2Bench = duration_cast<milliseconds>(t3 - t2);

    std::cout << std::endl;
    std::cout << "part1 took: " << part1Bench << std::endl;
    std::cout << "part2 took: " << part2Bench << std::endl;

    return EXIT_SUCCESS;
  } catch (std::exception e) {
    std::cerr << e.what() << std::endl;

    return EXIT_FAILURE;
  }
}