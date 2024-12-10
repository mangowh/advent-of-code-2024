#include <utils.h>

#include <fstream>
#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

namespace day10 {
void searchData(std::vector<std::vector<int>> data, int search, int x, int y,
                std::unordered_set<utils::Vector2D,
                                   utils::Vector2D::HashFunction> &foundNines) {
  if (search > 9) {
    foundNines.insert({x, y});

    return;
  }

  int data_width = static_cast<int>(data[0].size());
  int data_height = static_cast<int>(data.size());

  const std::vector<utils::Vector2D> coords{
      {x - 1, y}, {x, y - 1}, {x, y + 1}, {x + 1, y}};

  for (auto &coord : coords) {
    if (coord.x >= 0 && coord.y >= 0 && coord.x < data_width &&
        coord.y < data_height) {
      const auto &foundData = data[coord.y][coord.x];

      if (foundData == search) {
        searchData(data, search + 1, coord.x, coord.y, foundNines);
      }
    }
  }
}

inline void part1() {
  std::cout << "day10::part1" << std::endl;

  std::fstream f("./data/day10/input.txt");

  std::vector<std::vector<int>> data;

  std::string l;
  while (std::getline(f, l)) {
    std::vector<int> lineData;

    for (const char c : l) {
      lineData.push_back(std::atoi(&c));
    }

    data.push_back(lineData);
  }

  int totScore{0};

  for (int y = 0; y < data.size(); y++) {
    const auto &line = data[y];

    for (int x = 0; x < line.size(); x++) {
      const auto &val = line[x];
      if (val == 0) {
        std::unordered_set<utils::Vector2D, utils::Vector2D::HashFunction>
            foundNines;

        searchData(data, 1, x, y, foundNines);

        totScore += static_cast<int>(foundNines.size());
      }
    }
  }

  std::cout << totScore << std::endl;
}

inline void part2() { std::cout << "day10::part2" << std::endl; }
} // namespace day10