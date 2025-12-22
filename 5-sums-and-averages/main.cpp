#include <array>
#include <cstdlib>
#include <iostream>
#include <string>
#include <string_view>

#define MAX_NUMBERS 10
#define MAX_INPUT_STRING 256
#define SENTINEL '\n'

enum class loop_control {
  CONTINUE,
  STOP,
};

enum class validation_code {
  OK,
  NO_INPUT,
  INPUT_ERR,
};

loop_control input_loop();
validation_code validate(std::string_view input,
                         std::array<double, MAX_NUMBERS> &parsed_numbers,
                         int &num_parsed);

// -----------------------------------------------------------------------------
int main(void) {
  std::system("clear");
  std::cout
      << "====================================================================="
      << '\n'
      << "\tWelcome to the Summer and Averager\n"
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
      << "Please input up to %i floating point or integer numbers. Seperate\n"
      << "them with spaces. Simply enter a newline character to exit.\n"
      << std::endl;
  std::string input;
  std::getline(std::cin, input);
  std::array<double, MAX_NUMBERS> numbers{};
  int num_parsed;

  return loop_control::CONTINUE;
}
