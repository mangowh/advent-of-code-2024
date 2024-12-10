#include "day9.h"

#include <chrono>
#include <iostream>

using namespace day9;

int main() {
  using std::chrono::duration;
  using std::chrono::duration_cast;
  using std::chrono::high_resolution_clock;
  using std::chrono::milliseconds;

  try {
    auto t1 = high_resolution_clock::now();
    part1();
    auto t2 = high_resolution_clock::now();

    std::cout << std::endl;

    auto t3 = high_resolution_clock::now();
    part2();
    auto t4 = high_resolution_clock::now();

    auto part1Bench = duration_cast<milliseconds>(t2 - t1);
    auto part2Bench = duration_cast<milliseconds>(t4 - t3);

    std::cout << std::endl;
    std::cout << "part1 took: " << part1Bench << std::endl;
    std::cout << "part2 took: " << part2Bench << std::endl;

    return EXIT_SUCCESS;
  } catch (std::exception e) {
    std::cerr << e.what() << std::endl;

    return EXIT_FAILURE;
  }
}