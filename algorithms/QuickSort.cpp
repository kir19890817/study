#include "Driver.h"

int findPivot(std::vector<int>& input, int begin, int end)
{
  int pivot = input[begin];
  int i = begin - 1;
  int j = end + 1;
  while(true) {
    do ++i; while (input[i] < pivot);
    do --j; while(input[j] > pivot);
    if (i >= j) {
      return j;
    }
    std::swap(input[begin], input[end]);
  }
}

void doSort(std::vector<int>& input, int begin, int end)
{
  if (begin < end) {
    int pivot = findPivot(input, begin, end);
    doSort(input, begin, pivot);
    doSort(input, pivot + 1, end);
  }
};

void quickSort(std::vector<int>& input)
{
  doSort(input, 0, input.size() - 1);
}


int main(int argn, char* argv[]) 
{
  runMethod(quickSort);
}
