#include <utils.h>

#include <fstream>
#include <iostream>
#include <set>
#include <string>
#include <unordered_set>
#include <vector>

namespace day6 {

struct Vector2D {
  int x;
  int y;

  Vector2D(int x, int y) : x(x), y(y) {}

  bool operator==(const Vector2D &v) const { return (x == v.x && y == v.y); }

  Vector2D operator+(const Vector2D v) { return Vector2D{x + v.x, y + v.y}; }

  void operator+=(const Vector2D v) {
    x += v.x;
    y += v.y;
  }

  void rotate() {
    if (y == -1) {
      y = 0;
      x = 1;
    } else if (x == 1) {
      x = 0;
      y = 1;
    } else if (y == 1) {
      y = 0;
      x = -1;
    } else if (x == -1) {
      x = 0;
      y = -1;
    }
  }
  struct HashFunction {
    size_t operator()(const Vector2D &point) const {
      size_t xHash = std::hash<int>()(point.x);
      size_t yHash = std::hash<int>()(point.y) << 1;
      return xHash ^ yHash;
    }
  };
};

std::ostream &operator<<(std::ostream &os, Vector2D const &m) {
  return os << '[' << m.x << ':' << m.y << ']';
}

inline void part1() {
  std::cout << "day6::part1" << std::endl;

  int uniqueGuardPosNum{0};
  std::vector<Vector2D> obstaclesPositionsVec{};
  Vector2D guardPosition{0, 0};
  Vector2D boundaries{0, 0};

  std::ifstream myfile("./data/day6/input.txt");

  std::string line{};
  int currentLine{0};
  while (std::getline(myfile, line)) {
    std::vector<char> row(line.begin(), line.end());

    if (boundaries.x == 0) {
      boundaries.x = static_cast<int>(row.size());
    }

    for (int i = 0; i < row.size(); i++) {
      const char c = row[i];

      switch (c) {
      case ('#'): {
        Vector2D coords{i, currentLine};
        obstaclesPositionsVec.push_back(coords);
        break;
      }

      case ('^'): {
        guardPosition.x = i;
        guardPosition.y = currentLine;
        break;
      }
      }
    }

    currentLine++;
  }

  boundaries.y = currentLine;

  std::unordered_set<Vector2D, Vector2D::HashFunction> guardHistory{};

  Vector2D guardVelocity{0, -1};

  while (guardPosition.x >= 0 && guardPosition.y >= 0 &&
         guardPosition.x <= boundaries.x && guardPosition.y <= boundaries.y) {

    const auto nextGuardPosition = guardPosition + guardVelocity;

    if (utils::vectorIndexOf(obstaclesPositionsVec, nextGuardPosition) != -1) {
      guardVelocity.rotate();
    } else {
      guardHistory.insert(guardPosition);

      guardPosition += guardVelocity;
    }
  }

  uniqueGuardPosNum = static_cast<int>(guardHistory.size());

  std::cout << uniqueGuardPosNum << std::endl;
}

inline void part2() { std::cout << "day6::part2" << std::endl; }
} // namespace day6