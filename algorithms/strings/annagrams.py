from collections import Counter
from math import factorial

def cnk(n, k):
  return factorial(n) // factorial(k) // factorial(n - k)

def solve(string):
  length = len(string)
  counter = Counter()
  for i in range(length):
    for j in range(i + 1, length + 1):
      counter[''.join(sorted(string[i:j]))] += 1
  result = 0
  #print(counter)
  for i in counter:
    c = counter[i]
    if c > 1:
      result += cnk(c, 2)
  return result

if __name__ == '__main__':
  n = int(input().split()[0])
  for i in range(n):
    print(solve(input()))
