#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>
#include <string_view>
#include <strstream>

#define SENTINEL '\n'

// -----------------------------------------------------------------------------
enum class loop_control {
  CONTINUE,
  STOP,
};

enum class validation_code {
  OK,
  NO_INPUT,
  TOO_MANY,
  NOT_ENOUGH,
  INPUT_ERR,
};

// -----------------------------------------------------------------------------
class point {
public:
  int x;
  int y;

  point(const int x, const int y) : x(x), y(y) {}
  std::string to_string() const;
};

// -----------------------------------------------------------------------------
std::string point::to_string() const {
  std::ostringstream ss;
  ss << "point {\n"
     << std::setw(4) << "x = " << this->x << '\n'
     << std::setw(4) << "y = " << this->y << '\n'
     << '}' << std::endl;
  return ss.str();
}

loop_control input_loop();
validation_code validate(std::string_view input,
                         std::array<double, MAX_NUMBERS> &parsed_numbers,
                         short &numbers_len);

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
