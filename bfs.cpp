#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define pb push_back
#define fi first
#define se second
#define ll long long

vi adj[1001];
int vis[1001];
int distance[1001]

void bfs(int i) {
  queue<int> q;

  q.push(i);
  vis[i] = 1;
  distance[i] = 0;

  while (!q.empty()) {
    int front = q.front(); q.pop();

    // Manipule node
    
    for (auto v: adj[front]) {
      if (!vis[v]) {
        vis[v] = 1;
        distance[v] = distance[front] + 1;
        q.push(v);
      }
    }
  }

}

int main() {
  // Solution 

  return 0;
}

