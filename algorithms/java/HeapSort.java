class HeapSort implements SortMethod
{
  @Override
  public void sort(int[] input)
  {
    heapify(input);
    int last = input.length - 1;
    for (int i = last; i >= 0; --i) {
      int temp = input[0];
      input[0]= input[last];
      input[last] = temp;
      satisfyHeap(input, 0, --last);
    }
  }

  private void heapify(int[] input)
  {
    for (int i = input.length/2; i >= 0; --i) {
      satisfyHeap(input, i, input.length - 1);
    }
  }

  private void satisfyHeap(int[] input, int i, int length)
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
      int temp = input[i];
      input[i] = input[largest];
      input[largest] = temp;
      satisfyHeap(input, largest, length);
    }
  }

  static public void main(String[] argv)
  {
    Driver.run(new HeapSort());
  }
}
