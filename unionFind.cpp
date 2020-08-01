#include <bits/stdc++.h>
using namespace std;

// Initiate data structures
#define MAXN 100100
int parent[MAXN], size[MAXN];

// Function to find parent/head of x's set
int find(int x) {
  // if x's parent is itself, then x is the parent of the set
  if (parent[x] == x) return x;
  // else, then we should find recursively its parent and save it
  return parent[x] = find(parent[x]);
}

// function to join two differents sets
int join(int x, int y) {
  // Find x and y parents
  x = find(x);
  y = find(y);

  // if its the same, then nothing to do...
  if (x == y) return;

  // Otherwise, we need to set a parent,
  // so we will do that on the smallest set
  if (size[x] < size[y]) swap(x, y);
  // The biggest set will receive the other one and be the new parent.
  size[x] += size[y];
  parent[y] = x;
}

int main() {
  // Initializing set length array and set size array 
  for (int i = 0; i < MAXN; i++) {
    len[i] = 1;
    size[i] = 1;
  }
  // Initializing parents array
  for (int i = 0; i < MAXN; i++) parent[i] = i;

  // solution
  return 0;
}

