#include <cmath>
#include <cstdlib>
#include <iostream>

int add(const int x, const int y);
int subtract(const int x, const int y);
int multiply(const int x, const int y);
int divide(const int x, const int y);
int remainder_of(const int x, const int y);
int power(const int x, const int y);

// -----------------------------------------------------------------------------
int main(void) {
  std::system("clear");

  std::cout
      << "====================================================================="
      << std::endl
      << "\t\t\tWelcome" << std::endl
      << "====================================================================="
      << std::endl
      << std::endl;

  int x = 5;
  int y = 2;
  int result;

  result = add(x, y);
  std::cout << "result = " << result << std::endl << std::endl;

  result = subtract(x, y);
  std::cout << "result = " << result << std::endl << std::endl;

  result = multiply(x, y);
  std::cout << "result = " << result << std::endl << std::endl;

  result = divide(x, y);
  std::cout << "result = " << result << std::endl << std::endl;

  result = remainder_of(x, y);
  std::cout << "result = " << result << std::endl << std::endl;

  result = power(x, y);
  std::cout << "result = " << result << std::endl << std::endl;

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
int add(const int x, const int y) {
  std::cout << "adding " << x << " to " << y << std::endl;
  return x + y;
}

// -----------------------------------------------------------------------------
int subtract(const int x, const int y) {
  std::cout << "subtracting " << y << " from " << x << std::endl;
  return x - y;
}

// -----------------------------------------------------------------------------
int multiply(const int x, const int y) {
  std::cout << "multiplying " << x << " by " << y << std::endl;
  return x * y;
}

// -----------------------------------------------------------------------------
int divide(const int x, const int y) {
  std::cout << "dividing " << x << " by " << y << std::endl;
  return x / y;
}

// -----------------------------------------------------------------------------
int remainder_of(const int x, const int y) {
  std::cout << "getting the remainder of the division of " << x << " by " << y
            << std::endl;
  return x % y;
}

// -----------------------------------------------------------------------------
int power(const int x, const int y) {
  std::cout << "raising " << x << " to the power of " << y << std::endl;
  return std::pow(x, y);
}
