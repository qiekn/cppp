#include <initializer_list>
#include <iostream>

namespace ck {

struct IterLess {
  template <typename Iterator1, typename Iterator2>
  bool operator()(Iterator1 it1, Iterator2 it2) const {
    return *it1 < *it2;
  }
};

template <typename ForwardIterator, typename Comparator>
ForwardIterator MaxElement(ForwardIterator first, ForwardIterator last, Comparator comp) {
  if (first == last) {
    return first;
  }

  ForwardIterator result = first;
  while (++first != last) {
    if (comp(result, first)) {
      result = first;
    }
  }
  return result;
}

template <typename ForwardIterator>
inline ForwardIterator MaxElement(ForwardIterator first, ForwardIterator last) {
  return MaxElement(first, last, IterLess());
}

// 若参数 types 皆同，无需动用 variadic templates， 使用 initializer_list<T> 足矣
template <typename T>
inline T MaxCustom(std::initializer_list<T> list) {
  return *MaxElement(list.begin(), list.end());
}

}  // namespace ck

int main() {
  std::cout << ck::MaxCustom({57, 48, 60, 100, 20, 18}) << '\n';
  return 0;
}

/* --------------------------------- output --------------------------------- *
   100
 * -------------------------------------------------------------------------- */
