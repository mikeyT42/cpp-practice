#pragma once

#include <cstddef>
#include <memory>

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

  int &operator[](std::size_t i);
  const int &operator[](std::size_t i) const;
};

} // namespace practice
