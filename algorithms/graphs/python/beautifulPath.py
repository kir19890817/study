#! env python3

import sys
from collections import deque

def findCost(start, end, graph, cost):
  queue = deque([start])
    
  while queue:
    current = queue.popleft()

    for n in graph[current]:
      v = n['v']
      w = n['w']
      if v == current:
        continue
      needAdd = False
      for c in cost[current]:
        if c | w not in cost[v]:
          cost[v].add(c | w)
          needAdd = True
       if needAdd and v not in queue:
         queue.append(v)

  if not cost[end]:
    return -1
  return min(cost[end])
  
if __name__ == '__main__':
  line = input().split()
  n, m = [int(i) for i in line]
  graph = {}
  for i in range(1, n + 1):
    graph[i] = []
  for i in range(0, m):
    line = input().split()
    v1, v2, w = [int(i) for i in line]
    graph[v1].append({'v': v2, 'w': w})
    graph[v2].append({'v': v1, 'w': w})
  line = input().split()
  start, end = [int(i) for i in line]
  cost = {}
  for i in graph:
    cost[i] = set([])
  cost[start].add(0)
  print(findCost(start, end, graph, cost))
