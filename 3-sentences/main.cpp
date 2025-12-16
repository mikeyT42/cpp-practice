#include <cstdlib>
#include <iostream>

typedef enum {
  CONTINUE,
  STOP,
} loop_control;

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
      << std::endl
      << "\tWelcome to the Sentence Data Aggregator" << std::endl
      << "====================================================================="
      << std::endl
      << std::endl;

  loop_control l;
  do {
    l = input_loop();
  } while (l == CONTINUE);

  std::cout
      << "====================================================================="
      << std::endl
      << "\t\t\tThank you" << std::endl
      << "====================================================================="
      << std::endl
      << std::endl;

  return EXIT_SUCCESS;
}

// -----------------------------------------------------------------------------
loop_control input_loop() { return CONTINUE; }
