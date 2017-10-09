#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <iterator>
#include <set>
#include <deque>
#include <stdint.h>
using namespace std;

vector<long> bfs(long start, const vector<vector<bool>>& adjMatrix)
{
  set<long> checked;
  deque<long> queue;
  const auto& row = adjMatrix[start];
  if (std::none_of(row.begin(), row.end(), [](bool v) { return v; })) {
    return vector<long>({start});
  }

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

  auto result = vector<long>(checked.begin(), checked.end());
  //copy(result.begin(), result.end(), ostream_iterator<int>(cout, " "));
  //cout << endl;
  return result;
}

vector<long> calcClusters(const vector<vector<bool>>& adjMatrix)
{
  vector<long> clusters;
  //for (int i = 0; i < adjMatrix.size(); ++i) {
  //  for (int j = 0; j < adjMatrix.size(); ++j)
  //    cout << adjMatrix[i][j] << " ";
  //  cout << endl;
  //}
  set<long> unvisited;
  for (int i = 0; i < adjMatrix.size(); ++i)
    unvisited.insert(i);
  while (true) {
    if (unvisited.empty()) break;
    const auto cluster = bfs(*unvisited.begin(), adjMatrix);
    clusters.push_back(cluster.size());
    for (const auto& v : cluster) {
      unvisited.erase(v);
    }
  }
  
  return clusters;
}

vector<int> calcClusters1(const vector<vector<bool>>& adjMatrix)
{
  vector<set<long>> clusters;
  for (long i = 0; i < adjMatrix.size(); ++i) {
    const auto& row = adjMatrix[i];
    bool found = false;
    for (int j = 0; j < row.size(); ++j) {
      if (row[j]) {
         for (auto& c : clusters) {
           if (c.find(j) != c.end()) {
              c.insert(i);
              found = true;
              break;
           }
         }
      }
      if (found) break;
    }
    if (!found) clusters.push_back(set<long>({i}));
  }
  vector<int> result;
  result.reserve(clusters.size());

  for (const auto& c : clusters)
    result.push_back(c.size());
  return result;
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
        vector<vector<bool>> adjMatrix(n, vector<bool>(n));
        for(int a1 = 0; a1 < m; a1++){
            long city_1;
            long city_2;
            cin >> city_1 >> city_2;
            adjMatrix[city_1 - 1][city_2 - 1] = adjMatrix[city_2 - 1][city_1 - 1] = true;
        }
        int64_t cost = 0;
        for (const auto& c : calcClusters1(adjMatrix)) {
            int64_t deltaRoads = (c - 1) * croad + clib;
            int64_t deltaLibs = c * clib;
            cost += min(deltaRoads, deltaLibs);
        }
        cout << cost << endl;
    }
    return 0;
}
