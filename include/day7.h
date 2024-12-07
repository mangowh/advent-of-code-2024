#include <utils.h>

#include <fstream>
#include <iostream>
#include <print>
#include <string>

namespace day7 {
namespace detail {}

inline void part1() {
  std::cout << "day7::part1" << std::endl;

  long long tot{0};

  std::ifstream myfile("./data/day7/input.txt");
  std::string line{};
  while (std::getline(myfile, line)) {
    const auto row = utils::splitStringByChar(line, ':');

    const auto result = std::stoll(row[0]);

    const auto valuesString = row[1].substr(1, row[1].size());
    const auto values = utils::splitStringByChar(valuesString, ' ');

    const auto slots = values.size() - 1;

    std::vector<bool> bits(slots);
    std::fill(bits.begin(), bits.end(), false);

    for (int i = 0; i < 1 << slots; i++) {
      for (int j = 0; j < slots; j++) {
        bits[j] = i & (1 << j);
      }

      long long sum{std::stoll(values[0])};

      for (int k = 0; k < bits.size(); k++) {
        const auto nextValue = std::stoll(values[k + 1]);

        if (bits[k]) {
          sum *= nextValue;
        } else {
          sum += nextValue;
        }
      }

      if (result == sum) {
        tot += sum;
        break;
      }
    }
  }

  std::cout << tot << std::endl;
}

inline void part2() { std::cout << "day7::part2" << std::endl; }
} // namespace day7