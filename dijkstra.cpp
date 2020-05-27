#include <bits/stdc++.h>
using namespace std;

#define INF (int)1e9
#define MAXN 1001
vector<pair<int, int>> adj[MAXN];
priority_queue<pair<int, int>> q;
int vis[MAXN];
int dis[MAXN];

void dijk(int ini) {
  for (int i = 1; i <= n; i++) dis[i] = INF;
  dis[ini] = 0;

  q.push({0, ini});
  while (!q.empty()) {
    int a = q.front().second; q.pop();
    if (vis[a]) continue;
    vis[a] = 1;

    for (auto v: adj[a]) {
      int b = v.first, w = adj[v].second;
      if (dis[a] + w < dis[b]) {
        dis[b] = dis[a] + w;
        q.push({-dis[b], b});
      }
    }
  }
}

int main() {
  // solution

  return 0;
}

