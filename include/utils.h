#include <algorithm>
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
} // namespace utils