#include <cmath>
#include <cstdlib>

#include "ftxui/dom/elements.hpp"
#include "ftxui/screen/screen.hpp"

int add(const int x, const int y);
int subtract(const int x, const int y);
int multiply(const int x, const int y);
int divide(const int x, const int y);
int remainder_of(const int x, const int y);
int power(const int x, const int y);

// -----------------------------------------------------------------------------
int main() {
  auto screen = ftxui::Screen::Create(ftxui::Dimension::Fixed(80),
                                      ftxui::Dimension::Fixed(30));

  int x = 5;
  int y = 2;

  auto document =
      ftxui::vbox({ftxui::hbox({ftxui::text("Adding " + std::to_string(x) +
                                            " to " + std::to_string(y) + "."),
                                ftxui::separator(),
                                ftxui::text(std::to_string(add(x, y)))}) |
                   ftxui::border});

  auto window = ftxui::window(ftxui::text("Arithmetic"), document);

  ftxui::Render(screen, window);
  screen.Print();

  return EXIT_SUCCESS;
}

// -----------------------------------------------------------------------------
int add(const int x, const int y) { return x + y; }

// -----------------------------------------------------------------------------
int subtract(const int x, const int y) { return x - y; }

// -----------------------------------------------------------------------------
int multiply(const int x, const int y) { return x * y; }

// -----------------------------------------------------------------------------
int divide(const int x, const int y) { return x / y; }

// -----------------------------------------------------------------------------
int remainder_of(const int x, const int y) { return x % y; }

// -----------------------------------------------------------------------------
int power(const int x, const int y) { return std::pow(x, y); }
