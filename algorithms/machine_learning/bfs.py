from anytree import Node, RenderTree
from collections import deque

def bfs(root, goal):
  checked = set([])
  queue = deque([])

  checked.add(root)
  queue.append(root)

  while queue:
    current = queue.queue.popleft()
    if current.name == goal:
      return current
    for node in current.children:
      if node not in checked:
        checked.add(node)
        queue.append(node)
  return None

def runTest():
  a = Node("a")
  b = Node("b", parent = a)
  c = Node("c", parent = a)
  d = Node("d", parent = b)
  e = Node("e", parent = b)
  f = Node("f", parent = c)
  g = Node("g", parent = c)
  if bfs(a, "g") != g:
    print("Failure!")
  else:
    print("Success!")

if __name__ == "__main__":
  runTest()
