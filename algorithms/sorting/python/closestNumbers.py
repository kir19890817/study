#!/usr/bin/env python

def getPairs(inArray):
	absArray = sorted(inArray, key = lambda x : abs(x[1]))
	absArray = sorted(absArray, key = lambda x : x[1])
	minDiff = abs(absArray[1][1] - absArray[0][1])
	pairs = [(inArray[absArray[0][0]][1], inArray[absArray[1][0]][1])]
	for i in range(2, len(absArray)):
		diff = abs(absArray[i][1] - absArray[i - 1][1])
		if diff == minDiff:
			pairs.append((inArray[absArray[i - 1][0]][1], inArray[absArray[i][0]][1]))
		elif diff < minDiff:
			minDiff = diff
			pairs = [(inArray[absArray[i - 1][0]][1], inArray[absArray[i][0]][1])]
	pairs = map(lambda x : (min(x), max(x)), pairs)
	pairs = sorted(pairs, key = lambda x : x[0])
	return pairs			

if __name__ == '__main__':
	n = int(input())
	array = [(index, int(x)) for index, x in enumerate(input().split())]
	print(' '.join(map(lambda x : str(x[0]) + ' ' + str(x[1]), getPairs(array))))