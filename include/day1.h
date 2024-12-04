#include <algorithm>
#include <fstream>
#include <iostream>
#include <vector>

namespace day1 {
namespace detail {
void loadFileData(std::vector<int> &leftArr, std::vector<int> &rightArr) {
  std::ifstream inf{"./data/day1/input.txt"};

  if (!inf) {
    throw "Error trying to read input file";
  }

  int a, b;
  while (inf >> a >> b) {
    leftArr.push_back(a);
    rightArr.push_back(b);
  }
}
} // namespace detail

inline void part1() {
  std::cout << "day1::part1" << std::endl;

  std::vector<int> leftArr{};
  std::vector<int> rightArr{};
  detail::loadFileData(leftArr, rightArr);

  std::sort(leftArr.begin(), leftArr.end());

  std::sort(rightArr.begin(), rightArr.end());

  int distanceSum{0};
  for (size_t i = 0; i < leftArr.size(); i++) {
    int left = leftArr[i];
    int right = rightArr[i];

    int distance = std::abs(left - right);

    distanceSum += distance;
  }

  std::cout << distanceSum << std::endl;
}

inline void part2() {
  std::cout << "day1::part2" << std::endl;

  std::vector<int> leftArr{};
  std::vector<int> rightArr{};
  detail::loadFileData(leftArr, rightArr);

  int similarityScore{0};
  for (const int search : leftArr) {
    auto count = std::count(rightArr.begin(), rightArr.end(), search);

    similarityScore += static_cast<int>(count) * search;
  }

  std::cout << similarityScore << std::endl;
}

} // namespace day1