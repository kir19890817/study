#include <iostream>
#include <map>
#include <algorithm>
#include <tuple>
#include <vector>
#include <utility>

using namespace std;

struct DisjointSet
{
  vector<int> elements;
  vector<int> parents;
  vector<int> ranks;
};

struct Graph
{
  vector<int> vertices;
  vector<tuple<int, int, int>> edges;
};

DisjointSet makeSet(const Graph& graph)
{
  DisjointSet result;
  for (const auto& v : graph.vertices) {
    if (find(result.elements.begin(), result.elements.end(), v) == result.elements.end()) {
      result.elements.push_back(v);
      result.parents.push_back(v);
      result.ranks.push_back(0);
    }
  }
  return result;
}

int findSet(int x, const DisjointSet& s)
{
  if (s.parents[x] == x)
    return x;
  return findSet(s.parents[x], s);
}

int kruskal(const Graph& graph)
{
  int result = 0;
  auto set = makeSet(graph);
  auto edges = graph.edges;
  sort(edges.begin(), edges.end(), 
      [](const tuple<int, int, int>& e1, const tuple<int, int, int>& e2) { return get<2>(e1) <= get<2>(e2); });
  for (const auto& edge : edges)
  {
    const auto root1 = findSet(get<0>(edge), set);
    const auto root2 = findSet(get<1>(edge), set);
    if (root1 != root2) {
      result += get<2>(edge);
      if (set.ranks[root1] < set.ranks[root2])
        set.parents[root1] = root2;
      else if (set.ranks[root1] > set.ranks[root2])
        set.parents[root2] = root1;
      else {
        set.parents[root2] = root1;
        ++set.ranks[root1];
      }
    }
  }
  return result;
}

int main()
{
    int n, m;
    cin >> n >> m;
    Graph g;
    g.vertices.push_back(0);
    for (int i = 0; i < n + 1; ++i)
        g.vertices.push_back(i);
    for (int i = 0; i < m; ++i) {
        int x, y, w;
        cin >> x >> y >> w;
        g.edges.push_back(make_tuple(x, y, w));
    }
    cout << kruskal(g) << endl;
}

