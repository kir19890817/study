#! env python3

import sys
from collections import deque
from collections import Counter

def bfs(start, graph):
  checked = set([])
  queue = deque([start])
  dist = {}
  for v in graph:
    dist[v] = sys.maxsize
  dist[start] = 0
  
  while queue:
    current = queue.popleft()
    checked.add(current)
    
    for n in graph[current]:
      if n in checked or dist[current] == sys.maxsize:
        continue
      alt = dist[current] + 6
      dist[n] = min(alt, dist[n])
      queue.append(n)
      
  return dist      

if __name__ == "__main__":
  q = int(input().strip())
  for a0 in range(q):
    n, m = input().strip().split(' ')
    n, m = [int(n), int(m)]
    g = {}
    for v in range(1, n + 1):
      g[v] = set([])
    for a1 in range(m):
      u, v = input().strip().split(' ')
      u, v = [int(u), int(v)]
      g[u].add(v)
      g[v].add(u)
    s = int(input().strip())
    result = bfs(s, g)
    del result[s]
    print(' '.join([str(result[key]) if result[key] != sys.maxsize else '-1' for key in result]))
