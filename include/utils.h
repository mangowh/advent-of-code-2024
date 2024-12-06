#include <algorithm>
#include <iterator>
#include <sstream>
#include <string>
#include <vector>

namespace utils {
template <typename T>
inline std::vector<T> splitStringByChar(std::string str, const char c) {
  std::vector<T> values;

  std::replace(str.begin(), str.end(), c, ' ');

  std::stringstream ss(str);
  T temp;
  while (ss >> temp) {
    values.push_back(temp);
  }

  return values;
}

template <typename T> inline int vectorIndexOf(std::vector<T> vector, T item) {
  auto found = std::find(vector.begin(), vector.end(), item);

  if (found != vector.end()) {
    return static_cast<int>(std::distance(vector.begin(), found));
  }

  return -1;
}
} // namespace utils