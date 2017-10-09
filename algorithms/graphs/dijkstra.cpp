#include <iostream>
#include <set>
#include <iterator>
#include <algorithm>
#include <map>
#include <vector>
#include <limits>

using namespace std;

vector<int> dijkstra(const map<int, map<int, int>>& graph, int source)
{
  set<int> vertexes;
  for(const auto& v : graph) {
    vertexes.insert(v.first);
  }
  vector<int> dist(vertexes.size(), numeric_limits<int>::max());
  dist[source] = 0;
  while (!vertexes.empty()) {
    int u = *vertexes.begin();
    int distU = dist[u];
    for (const auto& v : vertexes) {
      if (dist[v] < distU) {
        distU = dist[v];
        u = v;
      }
    }
    vertexes.erase(u);
    if (distU == numeric_limits<int>::max()) continue;
    for (const auto& n : graph.at(u)) {
      const auto alt = distU + n.second;
      if (alt < dist[n.first])
        dist[n.first] = alt;
    }
  }	
  for (auto& d : dist) {
    if (d == numeric_limits<int>::max()) d = -1;
  }
  return dist;
}

int main()
{
  int t;
  cin >> t;
  for(int a0 = 0; a0 < t; a0++){
    map<int, map<int, int>> graph;
    int n;
    int m;
    cin >> n >> m;
    graph[0].insert({});
    for(int a1 = 0; a1 < m; a1++){
      int x;
      int y;
      int r;
      cin >> x >> y >> r;
      if (graph.find(x) != graph.end() && graph[x].find(y) != graph[x].end()) {
        graph[x][y] = min(graph[x][y], r);
      }
      else {
        graph[x][y] = r;
      }
      if (graph.find(y) != graph.end() && graph[y].find(x) != graph[y].end()) {
        graph[y][x] = min(graph[y][x], r);
      }
      else {
        graph[y][x] = r;
      }
    }
    int s;
    cin >> s;
    const auto dist = dijkstra(graph, s);
    for (int i = 1; i < dist.size(); ++i) {
      if (i != s) {
        cout << dist[i] << " ";
      }
    }
    cout << endl;
  }
  return 0;
}
