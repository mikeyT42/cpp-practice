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
                         std::array<double, MAX_NUMBERS> &parsed_numbers,
                         short &numbers_len);
void sum_and_count(const std::array<double, MAX_NUMBERS> &numbers,
                   short &numbers_len, sums &sums, counts &counts);
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
  short numbers_len = 0;

  const validation_code code = validate(input, numbers, numbers_len);
  switch (code) {
  case validation_code::NO_INPUT:
    return loop_control::STOP;
  case validation_code::INPUT_ERR:
    std::cout << "You did not enter any valid numbers; please try again."
              << std::endl;
    return loop_control::CONTINUE;
  case validation_code::OK:
    // Our parsed input is inside the numbers array.
    // So is the numbers_len.
    break;
  }

  sums sums{};
  counts counts{};
  averages averages{};
  sum_and_count(numbers, numbers_len, sums, counts);
  average(sums, counts, averages);
  print_table(sums, counts, averages);

  return loop_control::CONTINUE;
}

// -----------------------------------------------------------------------------
validation_code validate(std::string_view input,
                         std::array<double, MAX_NUMBERS> &parsed_numbers,
                         short &numbers_len) {
  if (input.empty())
    return validation_code::NO_INPUT;

  std::istringstream line(input.data());
  std::string token;

  while (line >> token) {
    std::istringstream token_stream(token);
    double parsed_number;
    if (token_stream >> parsed_number &&
        numbers_len < parsed_numbers.max_size()) {
      parsed_numbers[numbers_len] = parsed_number;
      numbers_len++;
    }
  }

  if (numbers_len == 0)
    return validation_code::INPUT_ERR;

  return validation_code::OK;
}
