#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

namespace day2 {
namespace detail {
bool checkReport(std::vector<int> report) {
  bool allIncreasing{true};
  for (size_t i = 1; i < report.size(); i++) {
    if (report[i] <= report[i - 1]) {
      allIncreasing = false;
      break;
    }
  }

  bool allDecreasing{true};
  for (size_t i = 1; i < report.size(); i++) {
    if (report[i] >= report[i - 1]) {
      allDecreasing = false;
      break;
    }
  }

  bool differsByAtLeastOne{true};
  for (size_t i = 1; i < report.size(); i++) {
    if (std::abs(report[i] - report[i - 1]) < 1) {
      differsByAtLeastOne = false;
      break;
    }
  }

  bool differsByAtMostThree{true};
  for (size_t i = 1; i < report.size(); i++) {
    if (std::abs(report[i] - report[i - 1]) > 3) {
      differsByAtMostThree = false;
      break;
    }
  }

  return (allIncreasing || allDecreasing) && differsByAtLeastOne &&
         differsByAtMostThree;
}
} // namespace detail

inline void part1() {
  std::cout << "day2::part1" << std::endl;

  std::ifstream fileStream{"./data/day2/input.txt"};

  if (!fileStream) {
    throw "Error trying to read input file";
  }

  int validReports{0};
  std::string line;
  while (std::getline(fileStream, line)) {
    std::istringstream stream(line);

    int prevValue;
    int value;

    stream >> value;
    prevValue = value;
    stream >> value;

    bool increasing{value > prevValue};

    bool valid{std::abs(prevValue - value) >= 1 &&
               std::abs(prevValue - value) <= 3};

    do {
      bool allIncreasing{prevValue < value};
      bool allDecreasing{prevValue > value};

      bool differsByAtLeastOne = std::abs(prevValue - value) >= 1;
      bool differsByAtMostThree = std::abs(prevValue - value) <= 3;

      valid =
          ((increasing && allIncreasing) || (!increasing && allDecreasing)) &&
          differsByAtLeastOne && differsByAtMostThree;

      prevValue = value;
    } while (valid && stream >> value);

    if (valid) {
      validReports++;
    }
  }

  std::cout << validReports << std::endl;
}

inline void part2() {
  std::cout << "day2::part2" << std::endl;
  std::ifstream fileStream{"./data/day2/input.txt"};

  if (!fileStream) {
    throw "Error trying to read input file";
  }

  int validReports{0};

  std::string line;
  while (std::getline(fileStream, line)) {
    std::istringstream stream(line);

    std::vector<int> report;

    int entry{};
    while (stream >> entry) {
      report.push_back(entry);
    }

    if (detail::checkReport(report)) {
      validReports++;
    } else {
      int tries{static_cast<int>(report.size()) - 1};

      while (tries >= 0) {
        std::vector<int> copy(report);

        copy.erase(copy.begin() + tries);

        if (detail::checkReport(copy)) {
          validReports++;
          break;
        }

        tries--;
      }
    }
  }

  std::cout << validReports << std::endl;
}
} // namespace day2