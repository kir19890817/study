#!/usr/bin/python

from numpy.random import permutation
from numpy import polyfit
from numpy.linalg import norm

def ransacLinear(data, minRequired, maxIter, minFitting, threshold):
  iterations = 0
  bestFit = []
  bestError = float("inf")
  while iterations < maxIter:
    mayBeInliers = zip(*(permutation(data)[0:minRequired]))
    [mayBeBestFit, mayBeBestError, _, _, _] = polyfit(mayBeInliers[0], mayBeInliers[1], 1, full = True)
    if mayBeBestError < bestError:
      bestError = mayBeBestError
      bestFit = mayBeBestFit
    alsoInliers = []
    for candidate in set(data) - set(mayBeInliers):
      a = mayBeBestFit[0]
      b = -1
      c = mayBeBestFit[1]
      x0 = candidate[0]
      y0 = candidate[1]
      d = abs(a*x0 + b*y0 + c)/norm([a, b])
      if d < threshold:
        alsoInliers.append(candidate)
    if len(alsoInliers) > minFitting:
      temp = zip(*data)
      [betterFit, betterFitError, _, _, _] = polyfit(temp[0], temp[1], 1, full = True)
      if betterFitError < bestError:
        bestFit = betterFit
        bestError = betterFitError
      else:
        bestFit = mayBeBestFit
    iterations += 1
  return bestFit

def runTest():
  data = [(1, 1), (2, 2), (3, 3), (4, 4), (10, 100), (11, 200)]
  print("Data: " + str(data))
  bestFit = ransacLinear(data, len(data)/2, 100, len(data)/2, 0.1)
  if bestFit == []:
    print("Nothing found")
  else:
    print("Best fit: y = %f x + %f" % (bestFit[0], bestFit[1]))

if __name__ == "__main__":
  runTest()
