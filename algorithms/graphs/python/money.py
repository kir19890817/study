#! env python

from collections import Counter

def getCost(graph, mask):
  result = 0
  for v in graph:
    if 1 << v & mask:
      result += graph[v]['c']
  return result

def collectMoney(graph, counter):
  result = 0
  for v in graph:
    adjanced = graph[v]['adjanced']
    disconnected = []
    connected = []
    for path in counter:
      if not path & adjanced:
        disconnected.append(path)
      else:
        connected.append(path)
    if not connected:
      counter[1 << v] = graph[v]['c']
    for c in connected:
      mask = 1 << v | c & ~adjanced
      counter[mask] = getCost(graph, mask)
    for d in disconnected:
      mask = d | 1 << v
      counter[mask] = getCost(graph, mask)


def collectMoney1(graph, counter, passed = 0):
  result = 0
  for v in graph:
    if not (1 << v) & passed:
      node = graph[v]
      newPassed = passed | (1 << v) | node['adjanced']
      if newPassed not in counter:
        residentResult = collectMoney1(graph, counter, newPassed)
        alt = node['c'] + residentResult
        result = max(alt, result)
        counter[newPassed] = result
  return result

if __name__ == '__main__':
  nHouses, nRoads = [int(x) for x in input().split()]
  graph = {}
  money = [int(x) for x in input().split()]
  for i in range(1, nHouses + 1):
    graph[i] = {'c': money[i - 1], 'adjanced': 0}
  for i in range(nRoads):
    a, b = [int(x) for x in input().split()]
    graph[a]['adjanced'] |= 1 << b;
    graph[b]['adjanced'] |= 1 << a;
  counter = Counter()
  collectMoney(graph, counter)
  #for c in sorted(counter):
  #  print('%s %d' % (bin(c >> 1), counter[c]))
  values = list(counter.values())
  result = max(values)
  print(result, values.count(result))
  #print('%d %d' % collectMoney(graph))
