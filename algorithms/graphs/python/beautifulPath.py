#! env python3

import sys
from collections import deque
from collections import Counter

def bfs(start, end, graph, exclude):
  queue = deque([start])
  checked = set([])
  while queue:
    current = queue.popleft()
    if current == end:
      return True
    checked.add(current)
    for n in graph[current]:
      v, w = n['v'], n['w']
      if w | exclude > exclude:
        continue
      if not v in checked:
        queue.append(v)
  return False
    

def findCost(start, end, graph):
  i = 0
  while not bfs(start, end, graph, i):
    i += 1
    if i > 1023:
      return -1
  return i
  
if __name__ == '__main__':
  n, m = [int(i) for i in input().split()]
  graph = {}
  for i in range(1, n + 1):
    graph[i] = []
  for i in range(0, m):
    v1, v2, w = [int(i) for i in input().split()]
    graph[v1].append({'v': v2, 'w': w})
    graph[v2].append({'v': v1, 'w': w})
  start, end = [int(i) for i in input().split()]
  print(findCost(start, end, graph))

