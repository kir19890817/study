#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <map>
#include <set>
#include <utility>

using namespace std;

struct Graph
{
  set<int> vertices;
  set<pair<int, int>> edges;
};

vector<pair<int, int>> getEdgesWithLeafNodes(const Graph& graph)
{
  vector<pair<int, int>> result;
  vector<bool> isHead(graph.vertices.size() + 1, false);
  for (const auto& e : graph.edges) {
    isHead[e.first] = true;
  }
  for (const auto& e : graph.edges) {
    if (!isHead[e.second]) {
      result.push_back(e);
    }
  }
  return result;
}

map<int, vector<int>> getGroups(const vector<pair<int, int>> edges)
{
  map<int, vector<int>> result;
  for (const auto& e : edges) {
    result[e.first].push_back(e.second);
  }
  return result;
}

void reduceGraph(Graph& graph, const map<int, vector<int>>& groups)
{
  for (const auto& g : groups) {
    if (0 == g.second.size() % 2) {
      for (const auto& n : g.second) {
        graph.vertices.erase(n);
        graph.edges.erase(make_pair(g.first, n));
      }
    } else if (g.second.size() > 2) {
      const auto n1 = *g.second.begin();
      for (const auto& n : g.second) {
        if (n != n1) {
          graph.vertices.erase(n);
          graph.edges.erase(make_pair(g.first, n));
        }
      }
    }
  }
}

int solve(Graph graph)
{
  // while effects the graph
  //   get edges with leaf nodes
  //   from them select those with common parents and form groups
  //   replace groups with single node if having odd number of leafs and two if having even
  while(true) {
    const auto edgesWithLeafs = getEdgesWithLeafNodes(graph); 
    const auto groups = getGroups(edgesWithLeafs);
    const auto before = graph.vertices.size();
    reduceGraph(graph, groups);
    if (graph.vertices.size() == before) break;
  }
#if 1
  for (const auto& e : graph.edges) {
    cout << "(" << e.first << ", " << e.second << ")" << endl;
  }
#endif
  return getEdgesWithLeafNodes(graph).size() - 1;
}

int main()
{
  int n, m;
  cin >> n >> m;
  Graph g;
  for (int i = 1; i <= n; ++i) {
    g.vertices.insert(i);
  }
  for (int i = 0; i < m; ++i) {
    int x, y;
    cin >> x >> y;
    g.edges.insert(make_pair(y, x));
  }
  cout << solve(g) << endl;
  return 0;
}
