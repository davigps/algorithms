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

  // Size[i] represents the distance between parent i
  // and its farthest child.
  // if size of x is less than size of y, then new parent of x is y
  if (size[x] < size[y]) parent[x] = y;
  // Otherwise, the new parent of y is x
  if (size[x] > size[y]) parent[y] = x;
  // So, in general lines, the parent with smallest size will not be
  // parent anymore

  // if both have the same size, then choose one 
  // and increase its size by one
  if (size[x] == size[y]) {
    parent[x] = y;
    size[y]++;
  }
}

int main() {
  // solution

  return 0;
}

