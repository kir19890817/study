#include "Driver.h"

std::vector<int> merge(const std::vector<int>& left, 
                       const std::vector<int>& right)
{
  std::vector<int> result;
  result.reserve(left.size() + right.size());
  int leftHead = 0;
  int rightHead = 0;
  for (int i = 0; i < left.size() + right.size(); ++i) {
    if (leftHead < left.size() && (rightHead >= right.size() || left[leftHead] <= right[rightHead])) {
      result.push_back(left[leftHead++]);
    } else {
      result.push_back(right[rightHead++]);
    }
  }
  return result;
}


void mergeSort(std::vector<int>& input)
{
  if (input.size() <= 1) {
    return;
  }

  int middle = input.size() / 2;
  std::vector<int> left(input.begin(), input.begin() + middle);
  std::vector<int> right(input.begin() + middle, input.end());

  mergeSort(left);
  mergeSort(right);
  input = merge(left, right);
}

int main()
{
  runMethod(mergeSort);
  return 0;
}
