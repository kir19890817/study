#include <iostream>
#include <vector>
#include <set>
#include <deque>

using namespace std;

set<int> bfs(int start, vector<vector<bool>>& adjMatrix)
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
  return checked;
}

int main()
{
  vector<vector<bool>> adjMatrix(3, vector<bool>(3));
  adjMatrix[0][1] = true;
  adjMatrix[1][2] = true;
  const auto walked = bfs(0, adjMatrix);
  cout << "Walked through " << walked.size() << " elements\n";

  return 0;
}
