#include "Driver.h"

// Best-case: O(n)
// Worst-case: O(n^2)
// Extra space: O(1)

void bubbleSort(std::vector<int>& input)
{
  const auto size = input.size();
  for (int i = 0; i < size - 1; ++i) {
    for (int j = 0; j < size - i - 1; ++j) {
      if (input[j] > input[j + 1]) {
        std::swap(input[j], input[j + 1]);
      }
    }
  }
}

int main(int argn, char* argv[])
{
  runMethod(argn, argv, bubbleSort);
}
