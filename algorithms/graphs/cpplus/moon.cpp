#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
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

vector<int> clusters(int n, const map<int, set<long>>& graph) {
    vector<int> result;
    vector<bool> checked(n, false);
    for (int i = 0; i < checked.size(); ++i) {
        if (!checked[i]) {
           result.push_back(bfs(i, graph, checked));
        }
    }
    return result;
}

long solve(const vector<int>& clusters)
{
    int64_t result = 0;
    int64_t sum = 0;
    for (int i = 1; i < clusters.size(); ++i) {
	sum += clusters[i];
    }
    for (int i = 0; i < clusters.size(); ++i) {
      result += clusters[i]*sum;
      sum -= clusters[i];
    } 
    return result;
}

int main() {
    int n;
    int p;
    cin >> n >> p;
    map<int, set<long>> graph;
    for (int i = 0; i < n; ++i) {
        graph[i].insert({});
    }
    for (int i = 0; i < p; ++i) {
        int p1;
        int p2;
        cin >> p1 >> p2;
        graph[p1].insert(p2);
        graph[p2].insert(p1);
    }
    cout << solve(clusters(n, graph));
    return 0;
}
