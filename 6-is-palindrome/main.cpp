#include <cctype>
#include <cstdlib>
#include <iostream>
#include <string>
#include <string_view>

#define SENTINEL '\n'

enum class loop_control {
  CONTINUE,
  STOP,
};

loop_control input_loop();
std::string prepare_input(std::string_view input);
bool is_palindrome(std::string_view prepared_input);

// -----------------------------------------------------------------------------
int main(void) {
  std::system("clear");
  std::cout
      << "====================================================================="
      << '\n'
      << "\tWelcome to the Palindrome Checker\n"
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
  std::cout
      << "Please enter a string that is a palindrome; if you want to exit\n"
      << "then just hit enter. It can be a sentence or a word.\n"
      << std::endl;
  std::string input;
  std::getline(std::cin, input);
  if (input.empty())
    return loop_control::STOP;

  std::string prepared = prepare_input(input);

  if (is_palindrome(prepared)) {
    std::cout << "\n\"" << prepared << "\" is a palindrome.\n" << std::endl;
  } else {
    std::cout << "\n\"" << prepared << "\" is not a palindrome.\n" << std::endl;
  }

  return loop_control::CONTINUE;
}

// -----------------------------------------------------------------------------
std::string prepare_input(std::string_view input) {
  std::string prepared;
  for (unsigned char c : input) {
    if (!std::isalnum(c))
      continue;
    prepared += std::tolower(c);
  }
  return prepared;
}

// -----------------------------------------------------------------------------
bool is_palindrome(std::string_view prepared_input) {
    prepared_input.begin()
}
