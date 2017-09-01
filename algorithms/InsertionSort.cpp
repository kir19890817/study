#include "Driver.h"

// Best-case: O(n)
// Worst-case (AND AVERAGE!): O(n^2)
// Note: internal loop has (n^2)/4 iterations
// Extra space: O(1)

template <typename T>
void insertionSort(std::vector<T>& input) 
{
  for (int i = 1; i < input.size(); ++i) {
    T key = input[i];
    int j = i - 1;
    while (j >= 0 && input[j] > key) {
      std::swap(input[j], input[j + 1]);
      --j;
    }
    input[j + 1] = key;
  }
}

int main(int argn, char* argv[]) {
  runMethod(argn, argv, insertionSort<int>);
  return 0;
}
