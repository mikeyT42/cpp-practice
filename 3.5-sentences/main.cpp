#include <cctype>
#include <cstdlib>
#include <string>

#include "ftxui/component/component.hpp"
#include "ftxui/component/screen_interactive.hpp"
#include "ftxui/dom/elements.hpp"
#include "ftxui/dom/table.hpp"
#include "ftxui/screen/color.hpp"

// -----------------------------------------------------------------------------
typedef std::vector<std::string> table_row;

// -----------------------------------------------------------------------------
int keystrokes(std::string_view input);
int alpha_chars(std::string_view input);
int digit_chars(std::string_view input);
int vowels(std::string_view input);

// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------
int main() {
  const std::string PROMPT =
      "Please input a sentence. If you want to exit, just hit enter.";
  std::string input;
  auto screen = ftxui::ScreenInteractive::Fullscreen();

  auto sentence_input = ftxui::Input(&input);
  auto component = ftxui::Container::Vertical({sentence_input});
  auto quit_button = ftxui::Button("Quit", screen.ExitLoopClosure());

  // clang-format off
  auto renderer = ftxui::Renderer(component, [&] {
      auto table = ftxui::Table({
          {"Keystrokes:", std::to_string(keystrokes(input))},
          {"Alpha Characters:", std::to_string(alpha_chars(input))},
          {"Numeric Characters:", std::to_string(digit_chars(input))},
          {"Vowels:", std::to_string(vowels(input))},
      });
      table.SelectAll().Border(ftxui::LIGHT);

      // Select row from the second to the last.
      auto content = table.SelectRows(0, -1);
      // Alternate in between 3 colors.
      content.DecorateCellsAlternateRow(color(ftxui::Color::DarkKhaki), 3, 0);
      content.DecorateCellsAlternateRow(color(ftxui::Color::DarkSeaGreen), 3,
              1);
      content.DecorateCellsAlternateRow(color(ftxui::Color::DarkOrange), 3, 2);

      return ftxui::window(ftxui::text("Sentence Data Aggregator"),
          ftxui::vbox({
              ftxui::hbox({
                      ftxui::text("Welcome to the Sentence Data Aggregator")
                        | ftxui::bold | ftxui::italic
              }) | ftxui::flex | ftxui::center,
              ftxui::separator(),
              ftxui::hbox({
                      ftxui::text(PROMPT) | ftxui::center,
                      quit_button->Render() | ftxui::flex | ftxui::align_right
              }),
              sentence_input->Render(),
              ftxui::separator(),
              table.Render(),
              ftxui::separator(),
          })
      );
  });
  // clang-format on

  screen.Loop(renderer);
}

// -----------------------------------------------------------------------------
int keystrokes(std::string_view input) {
  int total_keystrokes = 0;

  for (const auto &c [[maybe_unused]] : input)
    total_keystrokes++;

  return total_keystrokes;
}

// -----------------------------------------------------------------------------
int alpha_chars(std::string_view input) {
  int total_alpha = 0;

  for (const auto &c : input) {
    if (std::isalpha(static_cast<unsigned char>(c)))
      total_alpha++;
  }

  return total_alpha;
}

// -----------------------------------------------------------------------------
int digit_chars(std::string_view input) {
  int total_digit = 0;

  for (const auto &c : input) {
    if (std::isdigit(static_cast<unsigned char>(c)))
      total_digit++;
  }

  return total_digit;
}

// -----------------------------------------------------------------------------
int vowels(std::string_view input) {
  int total_vowels = 0;

  for (const auto &c : input) {
    switch (c) {
    case 'a':
    case 'A':
    case 'e':
    case 'E':
    case 'i':
    case 'I':
    case 'o':
    case 'O':
    case 'u':
    case 'U':
      total_vowels++;
    }
  }

  return total_vowels;
}
