#include <fstream>
#include <iostream>
#include <regex>
#include <sstream>

namespace day3 {
namespace detail {}

inline void part1() {
  std::cout << "day3::part1" << std::endl;

  std::ifstream t("./data/day3/input.txt");
  std::stringstream buffer;
  buffer << t.rdbuf();
  std::string str{buffer.str()};

  std::regex exp("mul\\(([0-9]*),([0-9]*)\\)");
  std::smatch res;

  int sum{0};

  std::string::const_iterator searchStart(str.cbegin());
  while (regex_search(searchStart, str.cend(), res, exp)) {
    int m1 = std::stoi(res[1]);
    int m2 = std::stoi(res[2]);

    sum += m1 * m2;

    searchStart = res.suffix().first;
  }

  std::cout << sum << std::endl;
}

inline void part2() {
  std::cout << "day3::part2" << std::endl;

  std::ifstream t("./data/day3/input.txt");
  std::stringstream buffer;
  buffer << t.rdbuf();

  std::regex mulExp("mul\\(([0-9]*),([0-9]*)\\)");
  std::regex doExp("do\\(\\)");
  std::regex dontExp("don't\\(\\)");

  std::smatch match;

  int sum{0};

  bool enabled{true};
  std::string token{};
  while (std::getline(buffer, token, ')')) {
    token += ')';

    if (enabled) {
      if (std::regex_search(token, match, mulExp)) {
        int m1 = std::stoi(match[1]);
        int m2 = std::stoi(match[2]);

        sum += m1 * m2;
      }
    }

    if (std::regex_search(token, doExp)) {
      enabled = true;
    }

    if (std::regex_search(token, dontExp)) {
      enabled = false;
    }
  }

  std::cout << sum << std::endl;
}
} // namespace day3