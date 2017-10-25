#! env python3

import sys

def minUnfair(inarr, k):
    arr = sorted(inarr)
    fairness = sys.maxsize
    for i in range(len(arr) - k + 1):
        fairness = min(fairness, arr[i + k - 1] - arr[i])
    return fairness

if __name__ == '__main__':
    n = int(input().strip())
    k = int(input().strip())
    arr = []
    for i in range(n):
        arr.append(int(input().strip()))
    print(minUnfair(arr, k))