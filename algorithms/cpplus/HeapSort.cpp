#include "Driver.h"

void satisfyHeap(std::vector<int>& input, int i, int length)
{
  int left = 2*i;
  int right = 2*i + 1;
  int largest = i;
  if (left <= length && input[left] > input[largest]) {
    largest = left;
  }
  if (right <= length && input[right] > input[largest]) {
    largest = right;
  }
  if (largest != i) {
    std::swap(input[i], input[largest]);
    satisfyHeap(input, largest, length);
  }
}

void heapify(std::vector<int>& input)
{
  for (int i = (input.size()/2); i >= 0; --i) {
    satisfyHeap(input, i, input.size() - 1);
  }
}

void heapSort(std::vector<int>& input)
{
  heapify(input);
  int last = input.size() - 1;
  for (int i = last; i >= 0; --i) {
    std::swap(input[0], input[last--]);
    satisfyHeap(input, 0, last);
  }
}

int main(int argn, char* argv[])
{
  runMethod(heapSort);
  return 0;
}
