#include <execution>
#include <fstream>
#include <iostream>
#include <print>
#include <sstream>
#include <string>
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

  int blinkNum = 25;
  std::vector<long long> data;

  std::string stringValue;
  while (iss >> stringValue) {
    data.push_back(std::stoi(stringValue));
  }

  while (blinkNum--) {
    size_t count{0};

    std::for_each(std::execution::par, data.begin(), data.end(),
                  [&data, &count](auto &&item) {
                    auto num = item;

                    if (num == 0) {
                      num = 1;
                    }

                    std::string s = std::to_string(num);

                    if (s.length() % 2 == 0) {
                      std::string half = s.substr(0, s.length() / 2);
                      std::string otherHalf = s.substr(s.length() / 2);

                      long long firstNum = std::stoll(half);
                      long long secondNum = std::stoll(otherHalf);

                      num = firstNum;
                      data.insert(data.begin() + count + 1, secondNum);

                      count++;
                    }

                    num *= 2024;
                    count++;
                  });
  }
}
} // namespace day11