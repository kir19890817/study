#include "Driver.h"

template <typename T>
void countSort(std::vector<T>& input, T minimal, T maximal)
{
  std::vector<int> count(maximal - minimal + 1);
  std::vector<T> output(input.size());
  for (const auto& i : input) {
    ++count[i];
  }
  for (int i = 1; i < count.size(); ++i) {
    count[i] += count[i - 1];
  }
  for (const auto& i : input) {
    output[count[i] - 1] = i;
    --count[i];
  }
  input = output;
}

void doCountSort(std::vector<int>& input)
{
  countSort(input, 0, 100);
}

int main(int argn, char* argv[]) 
{
  runMethod(doCountSort);
  return 0;
}
