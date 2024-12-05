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

bool checkX_pattern(const std::vector<std::vector<char>> &matrix, int ax,
                    int ay, std::string pattern) {
  // nw M
  bool nw = (ax > 0 && ay > 0 && matrix[ay - 1][ax - 1] == pattern[0]);

  // ne S
  bool ne = (ax < (matrix.size() - 1) && ay > 0 &&
             matrix[ay - 1][ax + 1] == pattern[1]);

  // sw M
  bool sw = (ax > 0 && ay < (matrix[ax].size() - 1) &&
             matrix[ay + 1][ax - 1] == pattern[2]);

  // se S
  bool se = (ax < (matrix.size() - 1) && ay < (matrix[ax].size() - 1) &&
             matrix[ay + 1][ax + 1] == pattern[3]);

  if (nw && ne && sw && se) {
    return true;
  }

  return false;
}

int searchX_MAS(const std::vector<std::vector<char>> &matrix) {
  int count{0};

  for (int i = 0; i < matrix.size(); i++) {
    auto &row = matrix[i];

    for (int j = 0; j < row.size(); j++) {
      auto &c = row[j];

      if (c == 'A') {
        if (detail::checkX_pattern(matrix, j, i, "MSMS") ||
            detail::checkX_pattern(matrix, j, i, "MMSS") ||
            detail::checkX_pattern(matrix, j, i, "SSMM") ||
            detail::checkX_pattern(matrix, j, i, "SMSM")) {
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

inline void part2() {
  std::cout << "day4::part2" << std::endl;

  std::ifstream fileStream{"./data/day4/input.txt"};

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

  const int foundX_MAS{detail::searchX_MAS(data)};

  std::cout << foundX_MAS << std::endl;
}
} // namespace day4