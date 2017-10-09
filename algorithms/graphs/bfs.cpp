#include <iostream>
#include <vector>
#include <set>
#include <deque>

using namespace std;

int bfs(int start, vector<vector<bool>>& adjMatrix)
{
  set<int> checked;
  deque<int> queue;

  checked.insert(start);
  queue.push_back(start);

  while (!queue.empty()) {
    const auto current = queue.front();
    queue.pop_front();
    const auto row = adjMatrix[current];
    for (int i = 0; i < row.size(); ++i) {
      if (row[i] && checked.find(i) == checked.end()) {
        checked.insert(i);
        queue.push_back(i);
      }
    }
  }
  for (int i = 0; i < adjMatrix.size(); ++i) {
    if (checked.find(i) == checked.end()) {
      return i;
    }
  }
  return -1;
}

int main()
{
  vector<vector<bool>> adjMatrix(4, vector<bool>(4));
  adjMatrix[0][1] = true;
  adjMatrix[1][2] = true;
  int counter = 1;
  auto next = bfs(0, adjMatrix);
  while (next > 0) {
    next = bfs(next, adjMatrix);
    ++counter;
  }
  
  cout << "Found " << counter << " clusters\n";

  return 0;
}
