#include <bits/stdc++.h>
using namespace std;

#define MAXN 100100
int parent[MAXN], size[MAXN];
vector<pair<int, pair<int, int>>> edges;

vector<pair<int, int>> tree[MAXN];

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
  for (int i = 0; i < MAXN; i++) {
    parent[i] = i;
    size[i] = 1;
  }

  int vertices, numberOfEdges;
  cin >> vertices >> numberOfEdges;
  while (numberOfEdges--) {
    int a, b, weight;
    cin >> a >> b >> weight;

    edges.push_back({weight, {a, b}});
  }

  sort(edges.begin(), edges.end());

  int cost = 0;
  for (auto edge: edges) {
    int weight = edge.first;
    int a = edge.second.first, b = edge.second.second;

    if (find(a) != find(b)) {
      join(a, b);

      cost += weight;

      tree[a].push_back({b, weight});
      tree[b].push_back({a, weight});
    }
  }

  cout << "Total cost: " << cost << endl;

  return 0;
}