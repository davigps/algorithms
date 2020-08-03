#include <bits/stdc++.h>
using namespace std;

#define MAXN 100100
// Parent and size arrays for Union-Find algorithm
int parent[MAXN], size[MAXN];
// Vector to store all graph edges 
vector<pair<int, pair<int, int>>> edges;
// Vector where the result tree will be build
vector<pair<int, int>> tree[MAXN];

// Find and Join functions of Union-Find Algorithm
int find(int x) {
  if (parent[x] == x) return x;

  return parent[x] = find(parent[x]);
}

void join(int x, int y) {
  x = find(x);
  y = find(y);

  if (x == y) return;

  if (size[x] < size[y]) swap(x, y);
  size[x] += size[y];
  parent[y] = x;
}

int main() {
  // Initiate parent and size arrays
  for (int i = 0; i < MAXN; i++) {
    parent[i] = i;
    size[i] = 1;
  }

  // Enter number of vertices and number of Edges
  int vertices, numberOfEdges;
  cin >> vertices >> numberOfEdges;

  // For each edge, build edges vector, 
  // using weight as main information of the pair
  while (numberOfEdges--) {
    int a, b, weight;
    cin >> a >> b >> weight;

    edges.push_back({weight, {a, b}});
  }

  // Sort edges in ascending order by weight 
  sort(edges.begin(), edges.end());

  // Initiate build tree cost as zero
  int cost = 0;
  for (auto edge: edges) {
    int weight = edge.first;
    int a = edge.second.first, b = edge.second.second;

    // Check if "a" and "b" are already above same parent
    if (find(a) != find(b)) {
      // If not, join them
      join(a, b);

      // Add current edge weight to the total cost
      cost += weight;

      // You can build the result tree here for posterior use
      tree[a].push_back({b, weight});
      tree[b].push_back({a, weight});
    }
  }

  cout << "Total cost: " << cost << endl;

  return 0;
}