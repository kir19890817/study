#include "Driver.h"

#include <algorithm>
#include <iostream>
#include <iterator>

#include <assert.h>

void runMethod(std::function<void(std::vector<int>&)> processor)
{
  std::vector<int> input;
  input.reserve(100);
  for (int i = 100; i > 0; --i) {
    input.push_back(i);
  }
  std::vector<int> idealOutput = input;
  std::sort(idealOutput.begin(), idealOutput.end());
  processor(input);
  assert(input.size() == idealOutput.size());
  for (int i = 0; i < input.size(); ++i) {
    if (input[i] != idealOutput[i]) {
      std::cout << "Incorrect element " << input[i] << " instead of " << idealOutput[i] << std::endl;
      return;
    }
  }
  std::cout << "Test finished successful" << std::endl;
}