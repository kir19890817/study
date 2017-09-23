class InsertionSort implements SortMethod
{
  @Override
  public void sort(int[] input)
  {
    for (int i = 1; i < input.length; ++i) {
      int key = input[i];
      int j = i - 1;
      while (j >= 0 && input[j] > key) {
        int temp = input[j];
        input[j] = input[j + 1];
        input[j + 1] = temp;
        --j;
      }
      input[j + 1] = key;
    }
  }

  public static void main(String[] argv)
  {
    Driver.run(new InsertionSort());
  }
}
