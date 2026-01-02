#include "list.hpp"
#include <cstdlib>
#include <iostream>

int main(void) {
  std::system("clear");
  std::cout
      << "====================================================================="
      << '\n'
      << "\tWelcome to List Program.\n"
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
  for (int i = 0; i < (int)l.length; i++)
    std::cout << "item at " << i << " = " << l[i] << std::endl;

  l.put(10);
  std::cout << "List length = " << l.length << std::endl;
  for (int i = 0; i < (int)l.length; i++)
    std::cout << "item at " << i << " = " << l[i] << std::endl;

  l.shrink_to_fit();

  std::cout << "-----------------------------------------------------\n"
            << "\t\tFirst Reallocation.\n"
            << "-----------------------------------------------------\n"
            << std::endl;
  l.put(11);
  std::cout << "List length = " << l.length << std::endl;
  for (int i = 0; i < (int)l.length; i++)
    std::cout << "item at " << i << " = " << l[i] << std::endl;

  for (int i = 12; i < 21; i++)
    l.put(i);

  std::cout << "-----------------------------------------------------\n"
            << "\t\tSecond Reallocation.\n"
            << "-----------------------------------------------------\n"
            << std::endl;

  for (int i = 21; i < 31; i++)
    l.put(i);

  std::cout << "-----------------------------------------------------\n"
            << "\t\tThird Reallocation.\n"
            << "-----------------------------------------------------\n"
            << std::endl;

  for (int i = 31; i < 34; i++)
    l.put(i);

  std::cout << "List length = " << l.length << std::endl;
  for (int i = 0; i < (int)l.length; i++)
    std::cout << "item at " << i << " = " << l[i] << std::endl;

  std::cout << "-----------------------------------------------------\n"
            << "\t\tRemoving and Shrinking.\n"
            << "-----------------------------------------------------\n"
            << std::endl;

  const int popped = l.pop();
  std::cout << "Popped = " << popped << std::endl;
  l.pop();
  l.pop();
  l.shrink_to_fit();

  std::cout
      << "====================================================================="
      << '\n'
      << "\t\tThank you, come again.\n"
      << "====================================================================="
      << '\n'
      << std::endl;

  return EXIT_SUCCESS;
}
