class CountSort implements SortMethod
{
  private int minimal;
  private int maximal;

  public CountSort(int minimal, int maximal)
  {
    this.minimal = minimal;
    this.maximal = maximal;
  }

  @Override
  public void sort(int[] input)
  {
    int[] count = new int[maximal - minimal + 1];
    int[] output = new int[input.length];
    for (int i : input) {
      ++count[i];
    }
    for (int i = 1; i < count.length; ++i) {
      count[i] += count[i - 1];
    }
    for (int i : input) {
      output[count[i] - 1] = i;
      --count[i];
    }
    System.arraycopy(output, 0, input, 0, input.length);
  }

  public static void main(String[] argv)
  {
    Driver.run(new CountSort(0, 100)); 
  }
}
