#include "Driver.h"

#include <iostream>
#include <iterator>

void runMethod(int argn, char* argv[], 
               std::function<void(std::vector<int>&)> processor)
{
  if (argn <= 1) {
    return;
  }

  std::vector<int> input;
  input.reserve(argn);
  for (int i = 1; i < argn; ++i) {
    input.push_back(atoi(argv[i]));
  }
  processor(input);

  std::cout << "Sorted: ";
  std::copy(input.begin(), input.end(), std::ostream_iterator<int>(std::cout, ";"));
}
