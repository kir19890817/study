#include "Driver.h"

// Worst-case performance	О(n2)
// Best-case performance	О(n2)
// Average performance	О(n2)

template <typename T>
void selectionSort(std::vector<T>& input)
{
  for (int i = 0; i < input.size() - 1; ++i) {
    int minIndex = i;
    for (int j = i; j < input.size(); ++j) {
      if (input[j] < input[minIndex]) {
        minIndex = j;
      }
    }
    std::swap(input[minIndex], input[i]);
  }
}

int main(int argn, char* argv[])
{
  runMethod(selectionSort<int>);
  return 0;
}
