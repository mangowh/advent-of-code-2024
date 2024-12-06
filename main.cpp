#include <iostream>

#include "day5.h"

using namespace day5;

int main() {
  try {
    part1();
    part2();

    return EXIT_SUCCESS;
  } catch (std::exception e) {
    std::cerr << e.what() << std::endl;

    return EXIT_FAILURE;
  }
}