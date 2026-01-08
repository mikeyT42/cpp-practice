#include <array>
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <string>

#include "ftxui/dom/elements.hpp"
#include "ftxui/screen/screen.hpp"

// -----------------------------------------------------------------------------
typedef enum {
  FICTION,
  NON_FICTION,
  SCIENCE_FICTION,
  MYSTERY,
  BIOGRAPHY,
} genre;

// -----------------------------------------------------------------------------
class book {
public:
  const std::string title;
  const std::string author;
  const unsigned int year;
  const genre genre;

  book(const std::string title, const std::string author,
       const unsigned int year, const ::genre genre)
      : title(title), author(author), year(year), genre(genre) {}

  std::string genre_to_string() const;
  void print() const;
};

// -----------------------------------------------------------------------------
std::string book::genre_to_string() const {
  switch (this->genre) {
  case FICTION:
    return "Fiction";
  case NON_FICTION:
    return "Non-fiction";
  case SCIENCE_FICTION:
    return "Science Fiction";
  case MYSTERY:
    return "Mystery";
  case BIOGRAPHY:
    return "Biography";
  }
}

// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------
int main() {
return EXIT_SUCCESS;
}
