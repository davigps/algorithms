#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define pb push_back
#define fi first
#define se second
#define ll long long

vi adj[1001];
int vis[1001];

void dfs(int x) {
  vis[x] = 1;

  // Here manipulate the visited node.

  for (auto v: adj[x]) {
    if (!vis[v]) dfs(v);
  }
}

int main() {
  // Solution

  return 0;
}

