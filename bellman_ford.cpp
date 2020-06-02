#include <bits/stdc++.h>
using namespace std;

#define INF (int)1e9
#define MAXN 100100
// Vector of edges list
vector<tuple<int, int, int>> adj;
// Array of distances
int dis[1001];
int n;

// Bellman-Ford Algorithm O(n*m)
void bellford(int x) {
  // set all distances as Infinity to be reduced
  for (int i = 1; i <= n; i++) dis[i] = INF;

  // set initial distance as 0
  dis[x] = 0;
  // Iterate for n - 1 rounds to reduce the distance of every edge
  for (int i = 1; i <= n - 1; i++) {
    // Iterate for m edges 
    for (auto e: adj) {
      int a, b, w;
      tie(a, b, w) = e;
      // Update the distance to b with min value
      dis[b] = min(dis[b], dis[a] + w);
    }
  }
}

int main() {
  // Solution  

  return 0;
}

