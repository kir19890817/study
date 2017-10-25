#! env python3

import sys

def minimumAbsoluteDifference(n, inarr):
    arr = sorted(inarr)
    diff = sys.maxsize
    for i in range(1, len(arr)):
        diff = min(diff, abs(arr[i] - arr[i - 1]))
    return diff

if __name__ == "__main__":
    n = int(input().strip())
    arr = list(map(int, input().strip().split(' ')))
    result = minimumAbsoluteDifference(n, arr)
    print(result)
