#include <fstream>
#include <iostream>
#include <string>
#include <vector>

const std::string search{"XMAS"};

namespace day4 {
namespace detail {
bool searchXMASstring(const std::vector<std::vector<char>> &matrix, int x,
                      int y, const int xDirection, const int yDirection) {
  std::string xmas{};

  while (x < matrix.size() && y < matrix[x].size()) {
    xmas += matrix[y][x];

    if (xmas.size() >= 4) {
      break;
    }

    switch (xDirection) {
    case (1):
      x++;
      break;

    case (-1):
      x--;
      break;
    }

    switch (yDirection) {
    case (1):
      y++;
      break;

    case (-1):
      y--;
      break;
    }
  }

  return xmas == search;
}

int searchXMAS(const std::vector<std::vector<char>> &matrix) {
  int count{0};

  for (int i = 0; i < matrix.size(); i++) {
    auto &row = matrix[i];

    for (int j = 0; j < row.size(); j++) {
      auto &c = row[j];

      if (c == 'X') {
        // horizontal - e
        if (detail::searchXMASstring(matrix, j, i, +1, 0)) {
          count++;
        }

        // rtl - w
        if (detail::searchXMASstring(matrix, j, i, -1, 0)) {
          count++;
        }

        // vertical - n
        if (detail::searchXMASstring(matrix, j, i, 0, -1)) {
          count++;
        }

        // vertical - s
        if (detail::searchXMASstring(matrix, j, i, 0, +1)) {
          count++;
        }

        // diagonal - ne
        if (detail::searchXMASstring(matrix, j, i, +1, -1)) {
          count++;
        }

        // diagonal - se
        if (detail::searchXMASstring(matrix, j, i, +1, +1)) {
          count++;
        }

        // diagonal - nw
        if (detail::searchXMASstring(matrix, j, i, -1, -1)) {
          count++;
        }

        // diagonal - sw
        if (detail::searchXMASstring(matrix, j, i, -1, +1)) {
          count++;
        }
      }
    }
  }

  return count;
}
} // namespace detail

inline void part1() {
  std::cout << "day4::part1" << std::endl;

  std::ifstream fileStream{"./data/day4/input.txt"};
  // std::ifstream fileStream{"./data/day4/small_input.txt"};

  if (!fileStream) {
    throw "Error trying to read input file";
  }

  // matrix[Y][X]
  std::vector<std::vector<char>> data{};

  std::string line;
  int currentLineIdx = 0;
  while (std::getline(fileStream, line)) {
    std::vector<char> v{};

    for (char &c : line) {
      v.push_back(c);
    }

    data.push_back(v);

    currentLineIdx++;
  }

  const int foundXMAS{detail::searchXMAS(data)};

  std::cout << foundXMAS << std::endl;
}

inline void part2() { std::cout << "day$::part2" << std::endl; }
} // namespace day4