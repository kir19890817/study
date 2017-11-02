#! env python

from collections import Counter

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
    cost = graph[v]['c']
    if not connected:
      counter[1 << v] = cost
    for c in connected:
      mask = 1 << v | c & ~adjanced
      if not mask in counter:
        counter[mask] = counter[c & ~adjanced] + cost
    for d in disconnected:
      mask = d | 1 << v
      if not mask in counter:
        counter[mask] = counter[d] + cost

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
  values = list(counter.values())
  result = max(values)
  print(result, values.count(result))
