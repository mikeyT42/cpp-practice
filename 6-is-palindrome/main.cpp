#include <cstdlib>
#include <iostream>
#include <string>
#include <string_view>

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
