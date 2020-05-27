#include <bits/stdc++.h>
using namespace std;


// Initiate the data structures
vector<int> adj[1001]; // Adj list
int vis[1001]; // Visited list

void dfs(int x) {
  // set actual node as visited
  vis[x] = 1;

  // Here manipulate the visited node.

  // If not visited, then visit next node
  for (auto v: adj[x]) {
    if (!vis[v]) dfs(v);
  }
}

int main() {
  // Solution

  return 0;
}

