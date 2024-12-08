#include <utils.h>

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

namespace day8 {

inline void part1() {
  std::cout << "day8::part1" << std::endl;

  [[maybe_unused]] int uniqueAntinodesCount{0};

  std::ifstream fileStream{"./data/day8/input.txt"};

  if (!fileStream) {
    throw "Error trying to read input file";
  }

  std::unordered_map<char, std::vector<utils::Vector2D>> data;

  std::string line;
  int currentLine{0};
  int lineLength{0};
  while (std::getline(fileStream, line)) {
    lineLength = static_cast<int>(line.length());

    for (int i = 0; i < lineLength; i++) {
      const char c{line[i]};

      if (c != '.') {
        auto &v = data[c];
        v.push_back({i, currentLine});
      }
    }

    currentLine++;
  }

  std::unordered_set<utils::Vector2D, utils::Vector2D::HashFunction>
      uniqueAntinodes;

  for (const auto &[frequency, antennas] : data) {
    for (const auto &antenna1 : antennas) {
      for (const auto &antenna2 : antennas) {
        if (antenna1 == antenna2) {
          break;
        }

        utils::Vector2D firstAntinode{0, 0};
        utils::Vector2D secondAntinode{0, 0};

        if (antenna1.magnitude() > antenna2.magnitude()) {
          const auto dx = antenna1.x - antenna2.x;
          const auto dy = antenna1.y - antenna2.y;

          firstAntinode.x = antenna1.x + dx;
          firstAntinode.y = antenna1.y + dy;

          secondAntinode.x = antenna2.x - dx;
          secondAntinode.y = antenna2.y - dy;
        } else {
          const auto dx = antenna2.x - antenna1.x;
          const auto dy = antenna2.y - antenna1.y;

          firstAntinode.x = antenna2.x + dx;
          firstAntinode.y = antenna2.y + dy;

          secondAntinode.x = antenna1.x - dx;
          secondAntinode.y = antenna1.y - dy;
        }

        if (firstAntinode.x >= 0 && firstAntinode.y >= 0 &&
            firstAntinode.x < lineLength && firstAntinode.y < lineLength) {
          uniqueAntinodes.insert(firstAntinode);
        }

        if (secondAntinode.x >= 0 && secondAntinode.y >= 0 &&
            secondAntinode.x < lineLength && secondAntinode.y < lineLength) {
          uniqueAntinodes.insert(secondAntinode);
        }
      }
    }
  }

  uniqueAntinodesCount = static_cast<int>(uniqueAntinodes.size());

  std::cout << uniqueAntinodesCount << std::endl;
}

inline void part2() { std::cout << "day8::part2" << std::endl; }
} // namespace day8