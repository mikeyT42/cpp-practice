#include <array>
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <string>

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
void book::print() const {
  std::cout << "book {" << std::endl
            << "  title" << std::setw(4) << std::right << " = " << this->title
            << std::endl
            << "  author" << std::setw(3) << std::right << " = " << this->author
            << std::endl
            << "  year" << std::setw(5) << std::right << " = " << this->year
            << std::endl
            << "  genre" << std::setw(4) << std::right << " = "
            << this->genre_to_string() << std::endl
            << "}" << std::endl
            << std::endl;
}

// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------
int main(void) {
  std::system("clear");
  std::cout
      << "====================================================================="
      << std::endl
      << "\t\t\tWelcome" << std::endl
      << "====================================================================="
      << std::endl
      << std::endl;

  std::array<book, 6> library = {
      book("The Great Gatsby", "F. Scott Fitzgerald", 1925, FICTION),
      book("Harry Potter and the Sorcer's Stone", "J.K. Rowling", 1997,
           FICTION),
      book("The War of the Worlds", "H.G. Wells", 1898, SCIENCE_FICTION),
      book("Sherlock Holmes", "Arthur Conan Doyle", 1892, MYSTERY),
      book("Steve Jobs", "Arthur Isaacson", 2011, BIOGRAPHY),
      book("Philosophiae Naturalis Principia Mathematica", "Sir Isaac Newton",
           1687, NON_FICTION),
  };

  std::cout << "Our library has " << library.size() << " book(s)." << std::endl
            << std::endl;

  library[0].print();
  library[1].print();
  library[2].print();
  library[3].print();
  library[4].print();
  library[5].print();

  std::cout
      << "====================================================================="
      << std::endl
      << "\t\t\tThank you" << std::endl
      << "====================================================================="
      << std::endl
      << std::endl;

  return EXIT_SUCCESS;
}
