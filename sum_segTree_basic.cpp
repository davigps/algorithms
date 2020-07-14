#include <bits/stdc++.h>
using namespace std;

#define MAXN 100100
// Initializing data structures, the segtree must have 4 times more space than original array
int n, segtree[4 * MAXN], array[MAXN];

// SegmentTree build function
// Must run in main with initial values, like: (v == 1, tl == 0, tr == n - 1)
void build(int a[], int v, int tl, int tr) {
  // If the two pointers are equal, than its a leaf, so assign a value
  if (tl == tr) {
    segtree[v] = a[tl];
  } else {
    // Else, calculate mid and build to left and the right child
    int tm = (tl + tr) / 2;
    build(a, v*2, tl, tm);
    build(a, v*2+1, tm+1, tr);
    // After the calls, assign its value according with its children
    segtree[v] = segtree[v*2] + segtree[v*2+1];
  }
}

// As this is a Sum segment Tree, we need a sum function
int sum(int v, int tl, int tr, int l, int r) {
  // If is a superflous case, return zero
  if (l > r) return 0;
  // If its a leaf, than, return leaf value
  if (l == tl && r == tr) return segtree[v];
  // Otherwise, return the sum of the two children
  int tm = (tl + tr) / 2;
  return sum(v*2, tl, tm, l, min(r, tm)) + sum(v*2+1, tm+1, tr, max(l, tm+1), r);
}

// Update the value of some position
void update(int v, int tl, int tr, int pos, int newVal) {
  // If its the desired leaf, than update its value
  if (tl == tr) {
    segtree[v] = newVal;
  // Otherwise, update the nearest child
  } else {
    int tm = (tl + tr) / 2;
    if (pos <= tm) {
      update(v*2, tl, tm, pos, newVal);
    } else {
      update(v*2+1, tm+1, tr, pos, newVal);
    }
    // After the update, the current vertex need a update too
    segtree[v] = segtree[v*2] + segtree[v*2+1];
  }
}
