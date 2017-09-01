#include "Driver.h"

// Best-case: O(n)
// Worst-case (AND AVERAGE!): O(n^2)
// Note: internal loop has (n^2)/2 iterations
// Extra space: O(1)

template <typename T>
void bubbleSort(std::vector<T>& input)
{
  const auto size = input.size();
  for (int i = 0; i < size - 1; ++i) {
    for (int j = 0; j < size - i - 1; ++j) {
      if (input[j] > input[j + 1]) {
        std::swap<T>(input[j], input[j + 1]);
      }
    }
  }
}

int main(int argn, char* argv[])
{
  runMethod(argn, argv, bubbleSort<int>);
  return 0;
}
