#include <cctype>
#include <cstdlib>
#include <string>

#include "ftxui/dom/elements.hpp"
#include "ftxui/dom/table.hpp"
#include "ftxui/screen/color.hpp"
#include "ftxui/screen/screen.hpp"

// -----------------------------------------------------------------------------
typedef std::vector<std::string> table_row;

// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------
int main() {
  std::vector<table_row> table_rows;
  // table_rows.reserve(library.size() + 1);
  table_rows.push_back({"Title", "Author", "Year", "Genre"});

  /*
  std::transform(library.cbegin(), library.cend(),
                 std::back_inserter(table_rows),
                 [](const book &b) { return b.to_table_row(); });
  */

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
  /*
  auto renderer =
      ftxui::vbox({
          ftxui::hbox({
                  ftxui::text("Welcome to the Sentence Data Aggregator")
                    | ftxui::bold | ftxui::italic
          }) | ftxui::flex | ftxui::center,
          ftxui::separator(),
          table.Render()| ftxui::center,
          ftxui::separator(),
          ftxui::hbox({
                  ftxui::text("Thank you") | ftxui::bold | ftxui::italic
          }) | ftxui::flex | ftxui::center
      });
  */
  // clang-format on

  auto window = ftxui::window(ftxui::text("Library"), document);

  auto screen = ftxui::Screen::Create(ftxui::Dimension::Full(),
                                      ftxui::Dimension::Fit(window));

  ftxui::Render(screen, window);
  screen.Print();
  return EXIT_SUCCESS;
}
