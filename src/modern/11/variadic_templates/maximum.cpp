#include <algorithm>
#include <iostream>

namespace ck {
int maximum(int n) {
  return n;
}

template <typename... Args>
int maximum(int n, Args... args) {
  return std::max(n, maximum(args...));
}
}  // namespace ck

int main() {
  std::cout << ck::maximum(57, 48, 60, 100, 20, 18) << '\n';
}

/* --------------------------------- output --------------------------------- *
   100
 * -------------------------------------------------------------------------- */
