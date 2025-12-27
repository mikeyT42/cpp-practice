#include <cstdlib>
#include <iostream>
#include <string>
#include <string_view>

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
