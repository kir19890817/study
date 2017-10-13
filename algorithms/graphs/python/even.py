from collections import Counter

def dfs(start, graph, weights, checked):
  checked.add(start)
  counter = 0

  for node in graph[start]:
    if node not in checked:
      delta = 1 + dfs(node, graph, weights, checked)
      weights[(start, node)] = delta
      counter += delta
  return counter

if __name__ == "__main__":
  w = Counter()
  checked = set([])
  line = input().split()
  n = int(line[0])
  m = int(line[1])
  graph = {};
  for i in range(1, n + 1):
    graph[i] = []
  for i in range(0, m):
    line = input().split()
    child = int(line[0])
    parent = int(line[1])
    graph[parent].append(child)
  dfs(1, graph, w, checked)
  result = 0
  for i in w:
    result += (w[i] % 2 == 0)
  #print(graph)
  #print(w)
  print(result)

