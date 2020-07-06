#include <bits/stdc++.h>
using namespace std;

#define MAXN 100100
#define INF (int)1e9

int n, m, vis[MAXN], dis[MAXN], parent[MAXN];
priority_queue<pair<int, int>> q;
vector<pair<int, int>> adj[MAXN];

void dijk(int x) {
  for (int i = 1; i <= n; i++) dis[i] = INF;
  dis[x] = 0;

  q.push({0, x});
  while (!q.empty()) {
    int a = q.top().second; q.pop();
    if (vis[a]) continue;
    vis[a] = 1;

    cout << "\n=======================\n";
    cout << "Looking " << a << endl;
    cout << "Its distance " << dis[a] << endl;

    cout << "\nNeighbors:\n";
    for (auto v: adj[a]) {
      int b = v.first, w = v.second;

      cout << "-----\n";
      cout << "Looking " << b << endl;
      cout << "Its distance " << dis[b] << endl;

      if (dis[a] + w < dis[b]) {
        dis[b] = dis[a] + w;
        cout << "~ Updated to " << dis[b] << endl;
        parent[b] = a;
        q.push({-dis[b], b});
      }
    }
  }
}

void printPath(int x) {
  cout << " => " << x;

  if (!parent[x]) {
    cout << endl;
    return;
  }
  printPath(parent[x]);
}

int main() {
  cin >> n >> m;

  while (m--) {
    int a, b, w;
    cin >> a >> b >> w;
    adj[a].push_back({b, w});
    adj[b].push_back({a, w});
  }
  
  dijk(1);

  cout << "\n\nDistance to N: " << dis[n] << endl;
  cout << "Shortest Path:\n";
  printPath(n);

  return 0;
}
