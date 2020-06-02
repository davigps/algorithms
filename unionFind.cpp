#include <bits/stdc++.h>
using namespace std;

// Initiate data structures
#define MAXN 100100
int parent[MAXN], len[MAXN], size[MAXN];

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

  // len[i] represents the distance between parent i
  // and its farthest child.
  // if length of x is less than length of y, then new parent of x is y
  // And set size of y is now increased by size of x
  if (len[x] < len[y]) {
    parent[x] = y;
    size[y] += size[x];
  }
  // Otherwise, the new parent of y is x
  // And set size of x is increased by size of y
  if (len[x] > len[y]) {
    parent[y] = x;
    size[x] += size[y];
  }
  // So, in general lines, the parent with smallest length will not be
  // parent anymore

  // if both have the same length, then choose one 
  // and increase its length by one
  if (len[x] == len[y]) {
    parent[x] = y;
    len[y]++;
    size[y] += size[x];
  }
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

