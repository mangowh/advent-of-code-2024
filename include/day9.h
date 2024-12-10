#include <fstream>
#include <iostream>
#include <print>
#include <string>
#include <vector>

namespace day9 {
namespace detail {}

inline void part1() {
  std::cout << "day9::part1" << std::endl;

  std::fstream fileStream("./data/day9/input.txt");

  std::vector<long long> data;

  long count{0};
  bool isFile{true};
  std::string line;
  std::getline(fileStream, line);

  for (const char c : line) {
    const int n = c - '0';

    for (size_t k = 0; k < n; k++) {
      if (isFile) {
        data.push_back(count / 2);
      } else {
        data.push_back(-1); // '.'
      }
    }

    count++;
    isFile = !isFile;
  }

  // for (auto el : data) {
  //   if (el == -1) {
  //     std::cout << '.';
  //   } else {
  //     std::cout << el;
  //   }
  // }
  // std::cout << std::endl;

  for (size_t i = 0; i < data.size(); i++) {
    if (data[i] == -1) {
      for (size_t k = data.size() - 1; k >= 0; k--) {
        if (i >= k) {
          goto exit;
        }

        if (data[k] != -1) {
          std::swap(data[i], data[k]);
          break;
        }
      }
    }
  }

exit:
  long long sum{0};
  for (int i = 0; i < data.size(); i++) {
    if (data[i] == -1) {
      break;
    }

    sum += data[i] * i;
  }

  std::cout << sum << std::endl;
}

inline void part2() {
  std::cout << "day9::part2" << std::endl;
  std::fstream fileStream("./data/day9/input.txt");

  std::vector<long long> data;

  long count{0};
  bool isFile{true};
  std::string line;
  std::getline(fileStream, line);

  for (const char c : line) {
    const int n = c - '0';

    for (size_t k = 0; k < n; k++) {
      if (isFile) {
        data.push_back(count / 2);
      } else {
        data.push_back(-1); // '.'
      }
    }

    count++;
    isFile = !isFile;
  }

  for (auto el : data) {
    if (el == -1) {
      std::cout << '.';
    } else {
      std::cout << el;
    }
  }
  std::cout << std::endl;

  int k = static_cast<int>(data.size()) - 1;
  while (k >= 0) {
    if (data[k] != -1) {
      const auto val = data[k];

      int valSize{1};
      while (k - valSize >= 0 && data[k - valSize] == val) {
        valSize++;
      }

      int i = 0;
      while (i < data.size()) {
        if (data[i] == -1) {
          int spaceSize{1};
          while (i + spaceSize < data.size() && data[i + spaceSize] == -1) {
            spaceSize++;
          }

          if (valSize <= spaceSize) {
            for (int spaceCursor = i; spaceCursor < i + valSize;
                 spaceCursor++) {
              data[spaceCursor] = val;
            }

            for (int valCursor = k; valCursor > k - valSize; valCursor--) {
              data[valCursor] = -1;
            }

            for (auto el : data) {
              if (el == -1) {
                std::cout << '.';
              } else {
                std::cout << el;
              }
            }
            std::cout << std::endl;

            i += valSize;

            break;
          }
        }

        i++;
      }

      k -= valSize;
    } else {
      k--;
    }
  }

  long long sum{0};
  for (int i = 0; i < data.size(); i++) {
    if (data[i] == -1) {
      break;
    }

    sum += data[i] * i;
  }

  std::cout << sum << std::endl;
}
} // namespace day9