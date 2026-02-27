#include <cstdint>
#include <functional>

class UUID {
public:
  UUID();
  UUID(uint64_t uuid);
  UUID(const UUID&) = default;

  operator uint64_t() const { return uuid_; }

private:
  uint64_t uuid_;
};

namespace std {
template <>
struct std::hash<UUID> {
  size_t operator()(const UUID& uuid) const noexcept {
    return std::hash<uint64_t>{}(uuid);  // or hoverever you access the uint64_t
  }
};
}  // namespace std
