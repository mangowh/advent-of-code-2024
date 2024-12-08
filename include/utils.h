#include <algorithm>
#include <iostream>
#include <iterator>
#include <sstream>
#include <string>
#include <vector>

namespace utils {
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

  double magnitude() const { return std::hypot(x, y); }

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

inline std::vector<std::string> splitStringByChar(std::string str,
                                                  const char c) {
  // old version
  // std::vector<T> values;

  // std::replace(str.begin(), str.end(), c, ' ');

  // std::stringstream ss(str);
  // T temp;
  // while (ss >> temp) {
  //   values.push_back(temp);
  // }

  // return values;

  std::vector<std::string> result;
  std::string token;
  std::istringstream tokenStream(str);

  while (std::getline(tokenStream, token, c)) {
    result.push_back(token);
  }
  return result;
}

template <typename T> inline int vectorIndexOf(std::vector<T> vector, T item) {
  auto found = std::find(vector.begin(), vector.end(), item);

  if (found != vector.end()) {
    return static_cast<int>(std::distance(vector.begin(), found));
  }

  return -1;
}
} // namespace utils