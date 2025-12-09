#include <functional>
#include <iostream>

class Add {
public:
  int operator()(int a, int b) const { return a + b; }
};

int main() {
  std::function<int(int, int)> callback = Add{};
  std::cout << "result: " << callback(1, 2) << '\n';
  return 0;
}

/* --------------------------------- output --------------------------------- *
   result: 3
 * -------------------------------------------------------------------------- */
