#include <array>
#include <cstdlib>
#include <string>

#include "ftxui/dom/elements.hpp"
#include "ftxui/dom/table.hpp"
#include "ftxui/screen/color.hpp"
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
typedef std::vector<std::string> table_row;

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
  table_row to_table_row() const;
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
table_row book::to_table_row() const {
  std::vector<std::string> row;
  row.reserve(4);

  row.push_back(this->title);
  row.push_back(this->author);
  row.push_back(std::to_string(this->year));
  row.push_back(this->genre_to_string());

  return row;
}

// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------
int main() {
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
  std::vector<table_row> table_rows;
  table_rows.reserve(library.size() + 1);
  table_rows.push_back({"Title", "Author", "Year", "Genre"});

  std::transform(library.cbegin(), library.cend(),
                 std::back_inserter(table_rows),
                 [](const book &b) { return b.to_table_row(); });

  auto table = ftxui::Table({table_rows});
  table.SelectAll().Border(ftxui::LIGHT);
  table.SelectRow(0).Decorate(ftxui::bold);
  table.SelectRow(0).SeparatorVertical(ftxui::LIGHT);
  table.SelectRow(0).Border(ftxui::DOUBLE);

  // Align right the "Release date" column.
  table.SelectColumn(2).DecorateCells(ftxui::align_right);

  // Select row from the second to the last.
  auto content = table.SelectRows(1, -1);
  // Alternate in between 3 colors.
  content.DecorateCellsAlternateRow(color(ftxui::Color::DarkKhaki), 3, 0);
  content.DecorateCellsAlternateRow(color(ftxui::Color::DarkSeaGreen), 3, 1);
  content.DecorateCellsAlternateRow(color(ftxui::Color::DarkOrange), 3, 2);

  // clang-format off

  auto document =
      ftxui::vbox({
          ftxui::hbox({
                  ftxui::text("Welcome") | ftxui::bold | ftxui::italic
          }) | ftxui::flex | ftxui::center,
          ftxui::separator(),
          table.Render()| ftxui::center,
          ftxui::separator(),
          ftxui::hbox({
                  ftxui::text("Thank you") | ftxui::bold | ftxui::italic
          }) | ftxui::flex | ftxui::center
      });
  // clang-format on

  auto window = ftxui::window(ftxui::text("Arithmetic"), document);

  auto screen = ftxui::Screen::Create(ftxui::Dimension::Full(),
                                      ftxui::Dimension::Fit(window));

  ftxui::Render(screen, window);
  screen.Print();
  return EXIT_SUCCESS;
}
