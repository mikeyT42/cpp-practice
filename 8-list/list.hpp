#pragma once

#include <memory>
#include <cstddef>

namespace practice {

class list {
private:
  std::size_t capacity;
  std::unique_ptr<int[]> data;

public:
  std::size_t length;

  list();
  ~list();
  void put(const int i);
  int pop();
  void shrink_to_fit();
};

} // namespace practice
