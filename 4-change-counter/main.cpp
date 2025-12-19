#include <cctype>
#include <cstdlib>
#include <iomanip>
#include <ios>
#include <iostream>
#include <string>

#define SENTINEL -1

enum class loop_control {
  CONTINUE,
  STOP,
};

loop_control input_loop();
bool validate(const double &input_cost);
void calculate_change(const double &input_cost, int &num_quarters,
                      int &num_dimes, int &num_nickels, int &num_pennies);

// -----------------------------------------------------------------------------
int main(void) {
  std::system("clear");
  std::cout
      << "====================================================================="
      << '\n'
      << "\t\tWelcome to the change counter!\n"
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
  double input_cost;
  std::cout
      << "Enter the amount you spent to two decimal places: the input must be\n"
         "between 0 and 1: -1 is to exit.\n"
      << std::endl;
  std::cin >> input_cost;
  if (input_cost == SENTINEL)
    return loop_control::STOP;

  if (validate(input_cost)) {
    std::cout
        << "You entered a number greater than 1 or less than zero that is not\n"
           "-1; please try again.\n"
        << std::endl;
    return loop_control::CONTINUE;
  }

  int num_quarters = 0, num_dimes = 0, num_nickels = 0, num_pennies = 0;
  calculate_change(input_cost, num_quarters, num_dimes, num_nickels,
                   num_pennies);

  std::cout << "\nThe amount you gave was $" << std::setprecision(2)
            << input_cost << ", your change is " << std::fixed << num_quarters
            << " Quarters,\n"
            << num_dimes << " Dimes, " << num_dimes << " Nickels, and "
            << num_pennies << " Pennies.\n"
            << std::endl;
  return loop_control::CONTINUE;
}

// -----------------------------------------------------------------------------
bool validate(const double &input_cost) {
  return input_cost < 0 || input_cost > 1;
}

// -----------------------------------------------------------------------------
void calculate_change(const double &input_cost, int &num_quarters,
                      int &num_dimes, int &num_nickels, int &num_pennies) {
  int cost_cents = 0;
  int change = 0;

  cost_cents = input_cost * 100;
  change = cost_cents;
  num_quarters = change / 25;
  change %= 25;
  num_dimes = change / 10;
  change %= 10;
  num_nickels = change / 5;
  change %= 5;
  num_pennies = change;
}
