#! evn python

import sys

def prim(start, graph):
  minTree = set([start])
  result = 0
  while len(minTree) != len(graph):
    delta = sys.maxsize
    vertex = 0
    for v in graph:
      for node in graph[v]:
        if (node['v'] not in minTree) and (node['w'] < delta) and (v in minTree):
          delta = node['w']
          vertex = node['v']
    result += delta
    minTree.add(vertex)
  return result

if __name__ == '__main__':
  line = input().split()
  n = int(line[0])
  m = int(line[1])
  graph = {}
  for i in range(1, n + 1):
    graph[i] = []
  for i in range(0, m):
    line = input().split()
    x = int(line[0])
    y = int(line[1])
    r = int(line[2])
    graph[x].append({'v': y, 'w': r})
    graph[y].append({'v': x, 'w': r})
  start = int(input())
  print(prim(start, graph))
