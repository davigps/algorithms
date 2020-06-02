#include <bits/stdc++.h>
using namespace std;

// Initiate data structures
vector<int> adj[1001]; // adj list 
int vis[1001]; // visited list
int dis[1001]; // distance list (optional)

void bfs(int i) {
  // create node queue
  queue<int> q;

  // add first node to the queue and set as visited
  q.push(i);
  vis[i] = 1;
  dis[i] = 0;

  // start bfs
  while (!q.empty()) {
    // get and remove current node
    int front = q.front(); q.pop();

    // Manipule node
    
    // See all next nodes
    for (auto v: adj[front]) {
      // if not visited, then visit
      if (!vis[v]) {
        vis[v] = 1;
        // set actual distance as previous distance plus one
        dis[v] = dis[front] + 1;
        q.push(v);
      }
    }
  }

}

int main() {
  // Solution 

  return 0;
}

