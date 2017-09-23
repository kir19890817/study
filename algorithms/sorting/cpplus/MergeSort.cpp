#include "Driver.h"

template<typename T>
std::vector<T> merge(const std::vector<T>& left, const std::vector<T>& right)
{
  std::vector<T> result;
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


template<typename T>
void mergeSort(std::vector<T>& input)
{
  if (input.size() <= 1) {
    return;
  }

  int middle = input.size() / 2;
  std::vector<T> left(input.begin(), input.begin() + middle);
  std::vector<T> right(input.begin() + middle, input.end());

  mergeSort(left);
  mergeSort(right);
  input = merge(left, right);
}

int main()
{
  runMethod(mergeSort<int>);
  return 0;
}
