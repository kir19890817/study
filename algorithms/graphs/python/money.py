#! env python

from collections import Counter

def collectForConnected(graph, counter):
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
    counter[1 << v] = cost
    for c in connected:
      mask = 1 << v | c & ~adjanced
      counter[mask] = counter[c & ~adjanced] + cost
    for d in disconnected:
      mask = d | 1 << v
      counter[mask] = counter[d] + cost

def collectForDisconnected(graph):
  result0 = 0
  disconnected = []
  disconnectedNulls = 0
  for v in graph:
    if not graph[v]['adjanced']:
      result0 += graph[v]['c']
      disconnectedNulls += graph[v]['c'] == 0
      disconnected.append(v)
  for v in disconnected:
    del graph[v]
  return result0, 2**disconnectedNulls

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
  result0, ways0 = collectForDisconnected(graph)
  if not graph:
    print(result0, ways0)
  else:
    counter = Counter()
    collectForConnected(graph, counter)
    values = list(counter.values())
    result = max(values)
    ways = values.count(result) + (result == 0)
    print(result + result0, ways0*ways)
