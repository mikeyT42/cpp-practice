#include "list.hpp"
#include <algorithm>
#include <iostream>
#include <memory>

#define GROWTH_FACTOR 10
#define INITIAL_LENGTH GROWTH_FACTOR

// -----------------------------------------------------------------------------
practice::list::list() {
  this->data = std::make_unique<int[]>(INITIAL_LENGTH);

  std::cout << "List created." << std::endl;

  this->length = 0;
  this->capacity = INITIAL_LENGTH;
}

// -----------------------------------------------------------------------------
practice::list::~list() {
  std::cout << "-----------------------------------------------------\n"
            << "\t\tDestroying list.\n"
            << "-----------------------------------------------------\n"
            << std::endl;
  this->data.reset();
  this->length = 0;
  this->capacity = 0;
}

// -----------------------------------------------------------------------------
int &practice::list::operator[](std::size_t i) { return this->data[i]; }

// -----------------------------------------------------------------------------
const int &practice::list::operator[](std::size_t i) const {
  return this->data[i];
}

// -----------------------------------------------------------------------------
int practice::list::pop() {
  int i = this->data[this->length - 1];
  this->length--;
  return i;
}

// -----------------------------------------------------------------------------
void practice::list::put(const int i) {
  std::cout << "length = " << this->length << " ; capacity = " << this->capacity
            << std::endl;

  if (this->length >= this->capacity) {
    std::cout << "Reallocating." << std::endl;
    const std::size_t new_capacity = this->capacity + GROWTH_FACTOR;
    std::cout << "new_capacity = " << new_capacity << std::endl;
    auto new_data = std::make_unique<int[]>(new_capacity);
    std::copy(this->data.get(), this->data.get() + this->capacity,
              new_data.get());

    this->data = std::move(new_data);
    this->capacity = new_capacity;
  }

  this->length++;
  this->data[this->length - 1] = i;
}

// -----------------------------------------------------------------------------
void practice::list::shrink_to_fit() {
  const std::size_t diff = this->capacity - this->length;
  const bool can_reduce_size = diff > 0;

  std::cout << "diff = " << diff << std::endl;
  std::cout << "can_reduce_size = " << can_reduce_size << std::endl;
  std::cout << "length = " << this->length << " ; capacity = " << this->capacity
            << std::endl;

  if (!can_reduce_size)
    return;

  const std::size_t new_capacity = this->length;
  std::cout << "new_capacity = " << new_capacity << std::endl;
  auto new_data = std::make_unique<int[]>(new_capacity);
  std::copy(this->data.get(), this->data.get() + this->length, new_data.get());

  this->data = std::move(new_data);
  this->capacity = new_capacity;
  std::cout << "length = " << this->length << " ; capacity = " << this->capacity
            << std::endl;
}
