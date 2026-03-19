#include <format>
#include <print>
#include <string>

struct Point {
  int x;
  int y;
};

template <>
struct std::formatter<Point> : std::formatter<std::string> {
  auto format(const Point& p, format_context& ctx) const {
    std::string str = std::format("({}, {})", p.x, p.y);
    return std::formatter<std::string>::format(str, ctx);
  }
};

int main() {
  Point point{3, 4};
  std::println("Point is {}", point);

  return 0;
}

// output: Point is (3, 4)
