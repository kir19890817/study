#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <map>
#include <set>
#include <utility>

using namespace std;

using Graph = map<int, vector<int>>;

int dfs(int start, Graph& graph, map<pair<int, int>, int>& weights, vector<bool>& checked)
{
  checked[start] = true;
  int counter = 0;
  for (const auto& n : graph[start]) {
    if (!checked[n]) {
      int delta = 1 + dfs(n, graph, weights, checked);
      weights[make_pair(start, n)] = delta;
      counter += delta;
    }
  }
  return counter;
}

int main()
{
  int n, m;
  cin >> n >> m;
  map<pair<int, int>, int> weights;
  vector<bool> checked(n + 1, false);
  Graph graph;
  for (int i = 1; i < n + 1; ++i) {
    graph[i] = {};
  }
  for (int i = 0; i < m; ++i) {
    int child, parent;
    cin >> child >> parent;
    graph[parent].push_back(child);
  }
  dfs(1, graph, weights, checked);
  int result = 0;
  for (const auto& w : weights) {
    result += (w.second % 2 == 0);
  }
  cout << result;
  return 0;
}
