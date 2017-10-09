#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <deque>

using namespace std;
int bfs(long start, const map<int, set<long>>& graph, vector<bool>& checked)
{
  deque<long> queue;

  queue.push_back(start);
  int count = 1;

  while (!queue.empty()) {
    const auto current = queue.front();
    queue.pop_front();
    for (const auto& adj : graph.at(current)) {
      if (!checked[adj]) {
        checked[adj] = true;
        ++count;
        queue.push_back(adj);
      }
    }
  }
  return count;
}

int main()
{
  map<int, set<long>> graph;
  graph[0] = {1, 2};
  graph[1] = {};
  graph[2] = {};
  vector<bool> checked(3, false);
  int counter = 0;
  for (int i = 0; i < checked.size(); ++i) {
    if (!checked[i]) {
       cout << "cluster with " << bfs(i, graph, checked) << " elements " << endl;
       ++counter;
    }
  }
  
  cout << "Found " << counter << " clusters\n";

  return 0;
}
