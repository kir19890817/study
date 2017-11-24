#!/usr/bin/env python

def getPairs(inArray):
	sortedArray = sorted(sorted(inArray, key = abs))
	minDiff = abs(sortedArray[1] - sortedArray[0])
	pairs = [(sortedArray[0], sortedArray[1])]
	for i in range(2, len(sortedArray)):
		diff = abs(sortedArray[i] - sortedArray[i - 1])
		if diff == minDiff:
			pairs.append((sortedArray[i], sortedArray[i - 1]))
		elif diff < minDiff:
			minDiff = diff
			pairs = [(sortedArray[i - 1], sortedArray[i])]
	pairs = map(lambda x : (min(x), max(x)), pairs)
	pairs = sorted(pairs, key = lambda x : x[0])
	return pairs			

if __name__ == '__main__':
	n = int(input())
	array = [(int(x)) for x in input().split()]
	print(' '.join(map(lambda x : str(x[0]) + ' ' + str(x[1]), getPairs(array))))