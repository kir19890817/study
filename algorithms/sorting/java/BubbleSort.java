class BubbleSort implements SortMethod
{
  @Override
  public void sort(int[] input)
  {
    int size = input.length;
    for (int i = 0; i < size - 1; ++i) {
      for (int j = 0; j < size - 1; ++j) {
        if (input[j] > input [j + 1]) {
          int temp = input[j];
          input[j] = input[j + 1];
          input[j + 1] = temp;
        }
      }
    }
  }
  public static void main(String[] args)
  {
    Driver.run(new BubbleSort());
  }
}
