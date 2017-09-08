class Driver
{
  static void run(SortMethod method)
  {
    int[] input = new int[100];
    for (int i = 0; i < input.length; ++i) {
      input[i] = input.length - i - 1;
    }
    method.sort(input);
    for (int i = 0; i < input.length; ++i) {
      if (input[i] != i) {
        System.out.println("Incorrect value [" + i + "] " + input[i] + " != " + i);
        return;
      }
    }
    System.out.println("Test successfully passed");
  }
}
