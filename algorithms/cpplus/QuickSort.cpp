#include "Driver.h"

template <typename T>
int findPivot(std::vector<T>& input, int begin, int end)
{
  int pivot = input[begin];
  int i = begin - 1;
  int j = end + 1;
  while(true) {
    do ++i; while (input[i] < pivot);
    do --j; while (input[j] > pivot);
    if (i >= j) {
      return j;
    }
    std::swap(input[begin], input[end]);
  }
}

template <typename T>
void quickSort(std::vector<T>& input, int begin, int end)
{
  if (begin < end) {
    T pivot = findPivot(input, begin, end);
    quickSort(input, begin, pivot);
    quickSort(input, pivot + 1, end);
  }
};

void doQuickSort(std::vector<int>& input)
{
  quickSort(input, 0, input.size() - 1);
}


int main(int argn, char* argv[]) 
{
  runMethod(doQuickSort);
}
