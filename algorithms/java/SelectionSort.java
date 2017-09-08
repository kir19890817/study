class SelectionSort implements SortMethod
{
  @Override
  public void sort(int[] input)
  {
    for (int i = 0; i < input.length - 1; ++i) {
      int minIndex = i;
      for (int j = i; j < input.length; ++j) {
        if (input[j] < input[minIndex]) {
          minIndex = j;
        }
      }
      int temp = input[minIndex];
      input[minIndex] = input[i];
      input[i] = temp;
    }
  }

  public static void main(String[] argv)
  {
    Driver.run(new SelectionSort());
  }
}
