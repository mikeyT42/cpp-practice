#include <cmath>
#include <cstdlib>

#include "ftxui/screen/screen.hpp"
#include "ftxui/dom/elements.hpp"

int main() {
  auto screen =
      ftxui::Screen::Create(ftxui::Dimension::Full(), ftxui::Dimension::Full());

  auto window = ftxui::window(ftxui::text("Hi"), ftxui::text("me"));
  
  ftxui::Render(screen, window);
  screen.Print();

  return EXIT_SUCCESS;
}
