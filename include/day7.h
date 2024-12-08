#include <utils.h>

#include <array>
#include <fstream>
#include <iostream>
#include <list>
#include <print>
#include <ranges>
#include <string>
#include <tuple>
#include <vector>

// https://rosettacode.org/wiki/Permutations_with_repetitions#C++
struct Generator {
public:
  Generator(int s, int v) : cSlots(s), cValues(v) {
    a = new int[s];

    for (int i = 0; i < cSlots - 1; i++) {
      a[i] = 1;
    }
    a[cSlots - 1] = 0;

    nextInd = cSlots;
  }

  ~Generator() { delete a; }

  bool doNext() {
    for (;;) {
      if (a[nextInd - 1] == cValues) {
        nextInd--;
        if (nextInd == 0)
          return false;
      } else {
        a[nextInd - 1]++;
        while (nextInd < cSlots) {
          nextInd++;
          a[nextInd - 1] = 1;
        }

        return true;
      }
    }
  }

  void doPrint() {
    printf("(");
    for (int i = 0; i < cSlots; i++) {
      printf("%d", a[i]);
    }
    printf(")");
  }

  std::vector<int> getCombination() {
    std::vector<int> v{};

    for (int i = 0; i < cSlots; i++) {
      v.push_back(a[i]);
    }

    return v;
  }

private:
  int *a;
  int cSlots;
  int cValues;
  int nextInd;
};

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

inline void part2() {
  std::cout << "day7::part2" << std::endl;

  long long tot{0};

  std::ifstream myfile("./data/day7/input.txt");
  std::string line{};
  while (std::getline(myfile, line)) {
    const auto row = utils::splitStringByChar(line, ':');

    const auto result = std::stoll(row[0]);

    const auto valuesString = row[1].substr(1, row[1].size());
    const auto values = utils::splitStringByChar(valuesString, ' ');

    const int slots = static_cast<int>(values.size() - 1);

    Generator g(slots, 3);

    while (g.doNext()) {
      auto combination = g.getCombination();

      long long sum{std::stoll(values[0])};

      for (int k = 0; k < combination.size(); k++) {
        const auto nextValue = std::stoll(values[k + 1]);

        switch (combination[k]) {
        case (1): {
          sum *= nextValue;
          break;
        }
        case (2): {
          sum += nextValue;
          break;
        }
        case (3): {
          const auto t = std::to_string(sum);
          const auto n = std::to_string(nextValue);
          const auto conc = t + n;

          sum = stoll(conc);
          break;
        }
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
} // namespace day7