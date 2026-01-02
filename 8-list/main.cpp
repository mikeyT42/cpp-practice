#include "list.hpp"
#include <cstdlib>
#include <iostream>

int main(void) {
  std::system("clear");
  std::cout
      << "====================================================================="
      << '\n'
      << "\tWelcome the Point Inputter\n"
      << "====================================================================="
      << '\n'
      << std::endl;

  std::cout << "-----------------------------------------------------\n"
            << "\t\tCreating the List.\n"
            << "-----------------------------------------------------\n"
            << std::endl;

  practice::list l;
  std::cout << "List length = " << l.length << std::endl;

  std::cout << "-----------------------------------------------------\n"
            << "\t\tFilling the List.\n"
            << "-----------------------------------------------------\n"
            << std::endl;

  for (int i = 1; i < 10; i++)
    l.put(i);

  std::cout << "List length = " << l.length << std::endl;

  std::cout
      << "====================================================================="
      << '\n'
      << "\t\t\tThank you\n"
      << "====================================================================="
      << '\n'
      << std::endl;

  return EXIT_SUCCESS;
}
