#include <bits/stdc++.h>
using namespace std;

#define MAXN 100001
#define MAXB 500
// Initializing data structures
int nums[MAXN], blocks[MAXB], n, len;

// Query sum function
int query(int l, int r) {
  // Get block where l and r were inserted
  int cL = l/len, cR = r/len;

  // Initialize sum with 0
  int sum = 0;
  if (cL == cR) {
    // If l and r are in the same block, just iterate in array
    for (int i = l; i <= r; i++) {
      sum += nums[i];
    }
  } else {
    // Else, first, iterate at the left tail
    for (int i = l; i <= (cL + 1) * len - 1; i++) {
      sum += nums[i];
    }
    // Iterate in the blocks
    for (int i = cL+1; i <= cR-1; i++) {
      sum += blocks[i];
    }
    // Iterate in the right tail
    for (int i = cR * len; i <= r; i++) {
      sum += nums[i];
    }
  }

  return sum;
}

// Update in specific index
void update(int idx, int value) {
  // Get old value
  int old = nums[idx];
  // Update in the numbers array
  nums[idx] = value;

  // Update with the delta in the blocks array
  blocks[idx / len] += value - old;
}

int main() {
  cin >> n;

  // Get length and number of blocks
  len = ceil(sqrt(n + .0));

  // Initialize numbers array
  for (int i = 0; i < n; i++) {
    int num;
    cin >> num;
    nums[i] = num;
  }

  // Initiliaze blocks array with the sum
  for (int i = 0; i < n; i++) {
    blocks[i / len] += nums[i];
  }

  int queries;
  cin >> queries;

  // Answering queries
  while (queries--) {
    int type, l, r, value;
    cin >> type;

    // If it is a sum query
    if (type == 1) {
      cin >> l >> r;
      // Get the sum of interval
      cout << "Sum: " << query(l, r) << endl;
    } else {
      cin >> l >> value;

      // Update at specific index
      update(l, value);

      cout << "updated." << endl;
    }
  }

  return 0;
}
