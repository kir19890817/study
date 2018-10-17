import sys

from collections import deque

def dfs(start, graph, discovered, finished):
  discovered.add(start)
  for v in graph[start]:
    if v in finished:
      print('forward or cross %d->%d' % (start, v))
      continue
    if v in discovered:
      print('back %d->%d' % (start, v))
      continue
    print('tree %d->%d' % (start, v))
    dfs(v, graph, discovered, finished)
  finished.append(start)

if __name__ == '__main__':
  #g = {1 : [2, 4, 3], 2 : [3], 3 : [1], 4 : [2]}
  #g = {1 : [2, 3, 4], 2 : [3], 3 : [1], 4 : [2]}
  # g = {1 : [2, 3, 4], 2 : [1, 3], 3 : [1], 4 : [1]}
  g = {1: [2], 2: [3], 3: []}
  discovered = set([])
  finished = deque([])
  dfs(1, g, discovered, finished)
