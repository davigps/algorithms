#include <bits/stdc++.h>
using namespace std;

// Initializing data structures...
// Defining INFINITY
#define INF (int)1e9
// Defining MAX value
#define MAXN 1001
// Creating Adjacency List with pairs {node, weigth}
vector<pair<int, int>> adj[MAXN];
// Creting distance priority queue with pairs {-distance, node}
priority_queue<pair<int, int>> q;
// Array of processed nodes
int vis[MAXN];
// Array of distances, must be initialized with INF values
int dis[MAXN];

// Dijkstra Algorithm Function
void dijk(int ini) {
  // Initialize distances with INF to be reduced
  for (int i = 1; i <= MAXN; i++) dis[i] = INF;
  // Distance to initial node is 0
  dis[ini] = 0;

  // Push initial node to be processed
  q.push({0, ini});
  while (!q.empty()) {
    // Get first node and pop it
    int a = q.top().second; q.pop();
    // if processed, then go to the next interation
    if (vis[a]) continue;
    // Otherwise, mark as processed
    vis[a] = 1;

    // Proccess node here

    // Visit each neighbor from adjacency list
    for (auto v: adj[a]) {
      // Get current neighbor and its weigth
      int b = v.first, w = v.second;

      // If the distance between the nodes is less than current
      // distance marked in node b, replace them
      if (dis[a] + w < dis[b]) {
        dis[b] = dis[a] + w;
        // Add current node to priority queue to be processed
        q.push({-dis[b], b});
      }
    }
  }
}

int main() {
  // solution

  return 0;
}

