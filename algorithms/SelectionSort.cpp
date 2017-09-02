#include "Driver.h"

void selectionSort(std::vector<int>& input)
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
  runMethod(selectionSort);
  return 0;
}
