#include <execution>
#include <fstream>
#include <iostream>
#include <print>
#include <sstream>
#include <string>
#include <utility>
#include <vector>

namespace day11 {
namespace detail {}

inline void part1() {
  std::cout << "day11::part1" << std::endl;

  std::fstream f("./data/day11/input.txt");

  std::string line;
  std::getline(f, line);

  auto iss = std::istringstream{line};

  int blinkNum = 25;
  std::vector<long long> data;

  std::string stringValue;
  while (iss >> stringValue) {
    data.push_back(std::stoi(stringValue));
  }

  while (blinkNum--) {
    for (int i = 0; i < data.size(); i++) {
      auto &num = data[i];

      if (num == 0) {
        num = 1;
        continue;
      }

      std::string s = std::to_string(num);

      if (s.length() % 2 == 0) {
        std::string half = s.substr(0, s.length() / 2);
        std::string otherHalf = s.substr(s.length() / 2);

        long long firstNum = std::stoll(half);
        long long secondNum = std::stoll(otherHalf);

        num = firstNum;
        data.insert(data.begin() + i + 1, secondNum);

        i++;
        continue;
      }

      num *= 2024;
    }
  }

  std::cout << data.size() << std::endl;
}

inline void part2() {
  std::cout << "day11::part2" << std::endl;

  std::fstream f("./data/day11/input.txt");

  std::string line;
  std::getline(f, line);

  auto iss = std::istringstream{line};

  int blinkNum = 75;
  std::vector<long long> data;

  std::string stringValue;
  while (iss >> stringValue) {
    data.push_back(std::stoi(stringValue));
  }

  std::mutex lock_;

  while (blinkNum--) {
    std::vector<std::pair<size_t, long long>> toAdd;

    std::cout << data.size() << std::endl;

    size_t count{0};
    std::for_each(std::execution::par_unseq, data.begin(), data.end(),
                  [&toAdd, count, &lock_](long long &num) {
                    if (num == 0) {
                      num = 1;
                    } else {
                      std::string s = std::to_string(num);
                      if (s.length() % 2 == 0) {
                        std::string half = s.substr(0, s.length() / 2);
                        std::string otherHalf = s.substr(s.length() / 2);

                        long long firstNum = std::stoll(half);
                        long long secondNum = std::stoll(otherHalf);

                        std::lock_guard<std::mutex> lg(lock_);

                        num = firstNum;
                        toAdd.push_back(std::make_pair(count + 1, secondNum));
                      } else {
                        num *= 2024;
                      }
                    }
                  });

    for (const auto &[idx, value] : toAdd) {
      // data.insert(data.begin() + idx + 1, value);
      data.push_back(value);
    }
  }

  std::cout << data.size() << std::endl;
}
} // namespace day11