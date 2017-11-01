#! env python

from collections import Counter
import copy

def excludeVertex(vertex, graph):
  result = copy.deepcopy(graph)
  toDelete = result[vertex]['adjanced']
  toDelete.add(vertex)
  for v in toDelete:
    del result[v]
  for v in result:
    for d in toDelete:
      if d in result[v]['adjanced']:
        result[v]['adjanced'].remove(d)
  return result 

def collectMoney(graph):
  result = 0
  for v in graph:
    node = graph[v]
    residentResult, _ = collectMoney(excludeVertex(v, graph))
    alt = node['c'] + residentResult
    result = max(alt, result)
  return result, 0

if __name__ == '__main__':
  nHouses, nRoads = [int(x) for x in input().split()]
  graph = {}
  money = [int(x) for x in input().split()]
  for i in range(1, nHouses + 1):
    graph[i] = {'c': money[i - 1], 'adjanced': set([])}
  for i in range(nRoads):
    a, b = [int(x) for x in input().split()]
    graph[a]['adjanced'].add(b)
    graph[b]['adjanced'].add(a)
  print(collectMoney(graph))
  #print('%d %d' % collectMoney(graph))
