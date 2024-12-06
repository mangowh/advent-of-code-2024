#include <utils.h>

#include <algorithm>
#include <fstream>
#include <iostream>
#include <set>
#include <sstream>
#include <string>
#include <unordered_map>
#include <utility>
#include <vector>

namespace day5 {
class Rules {
public:
  Rules() {};

  void addRule(int a, int b) { data.push_back({a, b}); }

  bool checkRow(std::vector<int> row) {
    std::set<int> rowSet(row.begin(), row.end());
    for (int i = 0; i < row.size(); i++) {
      const auto item = row[i];

      const auto valuesToCheck = getMatchingValues(item);

      for (const auto value : valuesToCheck) {
        const auto idx_it = std::find(row.begin(), row.end(), value);

        if (idx_it != row.end()) {
          const auto index = std::distance(row.begin(), idx_it);
          if (index < i) {
            return false;
          }
        }
      }

      const auto keysToCheck = getMatchingKeys(item);

      for (const auto key : keysToCheck) {
        const auto idx_it = std::find(row.begin(), row.end(), key);

        if (idx_it != row.end()) {
          const auto index = std::distance(row.begin(), idx_it);
          if (index > i) {
            return false;
          }
        }
      }
    }

    return true;
  }

  std::set<int> getMatchingValues(int keySearch) {
    std::set<int> values;

    for (const auto &[key, value] : data) {
      if (key == keySearch) {
        values.insert(value);
      }
    }

    return values;
  }

  std::set<int> getMatchingKeys(int valSearch) {
    std::set<int> keys;

    for (const auto &[key, value] : data) {
      if (value == valSearch) {
        keys.insert(key);
      }
    }

    return keys;
  }

private:
  std::vector<std::pair<int, int>> data;
};

inline void part1() {
  std::cout << "day5::part1" << std::endl;

  std::ifstream myfile("./data/day5/input.txt");

  int middleCount{0};
  bool isRulesSection{true};
  Rules rules{};

  std::string line;
  if (!myfile.is_open()) {
    throw "Can't open file";
  }

  while (std::getline(myfile, line)) {
    if (line.size() == 0) {
      isRulesSection = false;
    } else if (isRulesSection) {
      auto values = utils::splitStringByChar<int>(line, '|');

      rules.addRule(values[0], values[1]);
    } else {
      auto values = utils::splitStringByChar<int>(line, ',');

      if (rules.checkRow(values)) {
        const auto middleIdx = values.size() / 2;

        middleCount += values[middleIdx];
      }
    }
  }

  myfile.close();

  std::cout << middleCount << std::endl;
}

inline void part2() { std::cout << "day5::part2" << std::endl; }
} // namespace day5