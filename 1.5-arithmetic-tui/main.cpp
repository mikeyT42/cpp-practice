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
  const int x = 5;
  const int y = 2;
  // clang-format off
  auto document =
      ftxui::vbox({
          ftxui::hbox({
                  ftxui::text("Welcome") | ftxui::bold | ftxui::italic
          }) | ftxui::flex | ftxui::center,
          ftxui::separator(),
          ftxui::hbox({
                  ftxui::text("Adding " + std::to_string(x) + " to " +
                          std::to_string(y) + "."),
                  ftxui::separator(),
                  ftxui::text(std::to_string(add(x, y)))
          }) | ftxui::border,
          ftxui::hbox({
                  ftxui::text("Subtracting " + std::to_string(y) + " from " +
                          std::to_string(x) + "."),
                  ftxui::separator(),
                  ftxui::text(std::to_string(subtract(x, y)))
          }) | ftxui::border,
          ftxui::hbox({
                  ftxui::text("Multiplying " + std::to_string(x) + " by " +
                          std::to_string(y) + "."),
                  ftxui::separator(),
                  ftxui::text(std::to_string(multiply(x, y)))
          }) | ftxui::border,
          ftxui::hbox({
                  ftxui::text("Dividing " + std::to_string(x) + " by " +
                          std::to_string(y) + "."),
                  ftxui::separator(),
                  ftxui::text(std::to_string(divide(x, y)))
          }) | ftxui::border,
          ftxui::hbox({
                  ftxui::text("Getting the remainder of the division of " +
                          std::to_string(x) + " by " + std::to_string(y) + "."),
                  ftxui::separator(),
                  ftxui::text(std::to_string(remainder_of(x, y)))
          }) | ftxui::border,
          ftxui::hbox({
                  ftxui::text("Raising " + std::to_string(x) +
                          " to the power of " + std::to_string(y) + "."),
                  ftxui::separator(),
                  ftxui::text(std::to_string(power(x, y)))
          }) | ftxui::border,
          ftxui::separator(),
          ftxui::hbox({
                  ftxui::text("Thank you") | ftxui::bold | ftxui::italic
          }) | ftxui::flex | ftxui::center
      });
  // clang-format on

  auto window = ftxui::window(ftxui::text("Arithmetic"), document);

  auto screen = ftxui::Screen::Create(ftxui::Dimension::Fixed(80),
                                      ftxui::Dimension::Fit(window));

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
