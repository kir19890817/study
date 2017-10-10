#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <iterator>
#include <map>
#include <set>
#include <deque>
#include <stdint.h>
using namespace std;

int bfs(long start, const map<int, set<long>>& graph, vector<bool>& checked)
{
  deque<long> queue;
  set<long> visited;

  queue.push_back(start);
  visited.insert(start);
  int count = 1;

  while (!queue.empty()) {
    const auto current = queue.front();
    queue.pop_front();
    visited.insert(current);
    for (const auto& adj : graph.at(current)) {
      if (!checked[adj]) {
        checked[adj] = true;
        queue.push_back(adj);
      }
    }
  }
  return visited.size();
}

int main() {
    int q;
    cin >> q;
    for(int a0 = 0; a0 < q; a0++){
        int n;
        int m;
        long clib;
        long croad;
        cin >> n >> m >> clib >> croad;
        map<int, set<long>> graph;
        for (int i = 0; i < n; ++i) 
          graph[i] = {};
        for(int a1 = 0; a1 < m; a1++){
            long city_1;
            long city_2;
            cin >> city_1 >> city_2;
            graph[city_1 - 1].insert(city_2 - 1);
            graph[city_2 - 1].insert(city_1 - 1);
        }
        int64_t cost = 0;
        vector<bool> checked(n, false);
        for (int i = 0; i < checked.size(); ++i) {
          if (!checked[i]) {
            const auto size = bfs(i, graph, checked);
            const auto cost1 = clib + (size - 1) * croad;
            const auto cost2 = clib * size;
            cost += min(cost1, cost2);
          }
        }
        cout << cost << endl;
    }
    return 0;
}

