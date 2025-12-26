#include <array>
#include <cstdlib>
#include <iostream>
#include <sstream>
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

struct sums {
  double positive;
  double negative;
  double overall;
};

struct counts {
  unsigned int positive;
  unsigned int negative;
  unsigned int overall;
};

struct averages {
  double positive;
  double negative;
  double overall;
};

loop_control input_loop();
validation_code validate(std::string_view input,
                         std::array<double, MAX_NUMBERS> &parsed_numbers);
void sum_and_count(const std::array<double, MAX_NUMBERS> &numbers, sums &sums,
                   counts &counts);
void average(const sums &sums, const counts &counts, averages &averages);
void print_table(const sums &sums, const counts &counts,
                 const averages &averages);

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
  std::cout << "Please input up to " << MAX_NUMBERS
            << " floating point or integer numbers. Seperate\n"
            << "them with spaces. Simply enter a newline character to exit.\n"
            << std::endl;
  std::string input;
  std::getline(std::cin, input);
  std::array<double, MAX_NUMBERS> numbers{};

  const validation_code code = validate(input, numbers);
  switch (code) {
  case validation_code::NO_INPUT:
    return loop_control::STOP;
  case validation_code::INPUT_ERR:
    std::cout << "You did not enter any valid numbers; please try again."
              << std::endl;
    return loop_control::CONTINUE;
  case validation_code::OK:
    break;
  }

  return loop_control::CONTINUE;
}

// -----------------------------------------------------------------------------
validation_code validate(std::string_view input,
                         std::array<double, MAX_NUMBERS> &parsed_numbers) {
  if (input.empty())
    return validation_code::NO_INPUT;

  std::istringstream line(input.data());
  double parsed_number;

  for (short i = 0; line >> parsed_number && i < parsed_numbers.max_size();
       i++) {
    parsed_numbers[i] = parsed_number;
    std::cout << "parsed_number = " << parsed_number << std::endl;
  }

  return validation_code::OK;
}
