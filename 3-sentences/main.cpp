#include <cctype>
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <string>

#define SENTINEL '\n'

enum class loop_control {
  CONTINUE,
  STOP,
};

loop_control input_loop();
int keystrokes(const std::string input);
int alpha_chars(const std::string input);
int digit_chars(const std::string input);
int vowels(const std::string input);

// -----------------------------------------------------------------------------
int main(void) {
  std::system("clear");
  std::cout
      << "====================================================================="
      << '\n'
      << "\tWelcome to the Sentence Data Aggregator\n"
      << "====================================================================="
      << '\n'
      << std::endl;

  loop_control l;
  do {
    l = input_loop();
  } while (l == loop_control::CONTINUE);

  std::cout
      << "====================================================================="
      << '\n'
      << "\t\t\tThank you\n"
      << "====================================================================="
      << '\n'
      << std::endl;

  return EXIT_SUCCESS;
}

// -----------------------------------------------------------------------------
loop_control input_loop() {
  std::string input;

  std::cout << "\n\nPlease input a sentence. If you want to exit, just hit "
            << "enter." << std::endl;
  std::getline(std::cin, input);
  if (input.size() == 0)
    return loop_control::STOP;

  const int total_keystrokes = keystrokes(input);
  std::cout << "\nKeystrokes: " << std::setw(10) << total_keystrokes
            << std::endl;
  const int total_alpha = alpha_chars(input);
  std::cout << "\nAlpha Characters: " << std::setw(4) << total_alpha
            << std::endl;
  const int total_digit = digit_chars(input);
  std::cout << "\nNumeric Characters: " << std::setw(2) << total_digit
            << std::endl;
  const int total_vowels = vowels(input);
  std::cout << "\nVowels: " << std::setw(14) << total_vowels << std::endl;

  return loop_control::CONTINUE;
}

// -----------------------------------------------------------------------------
int keystrokes(const std::string input) {
  int total_keystrokes = 0;

  for (const auto &c [[maybe_unused]] : input)
    total_keystrokes++;

  return total_keystrokes;
}

// -----------------------------------------------------------------------------
int alpha_chars(const std::string input) {
  int total_alpha = 0;

  for (const auto &c : input) {
    if (std::isalpha(static_cast<unsigned char>(c)))
      total_alpha++;
  }

  return total_alpha;
}

// -----------------------------------------------------------------------------
int digit_chars(const std::string input) {
  int total_digit = 0;

  for (const auto &c : input) {
    if (std::isdigit(static_cast<unsigned char>(c)))
      total_digit++;
  }

  return total_digit;
}

// -----------------------------------------------------------------------------
int vowels(const std::string input) {
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
