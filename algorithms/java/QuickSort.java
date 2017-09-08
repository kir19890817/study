class QuickSort implements SortMethod
{
  @Override
  public void sort(int[] input)
  {
    doSort(input, 0, input.length - 1);
  }

  private int findPivot(int[] input, int begin, int end)
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
      int temp = input[begin];
      input[begin] = input[end];
      input[end] = temp;
    }
  }

  private void doSort(int[] input, int begin, int end)
  {
    if (begin < end) {
      int pivot = findPivot(input, begin, end);
      doSort(input, begin, pivot);
      doSort(input, pivot + 1, end);
    }
  }

  public static void main(String[] argv)
  {
    Driver.run(new QuickSort());
  }
}
