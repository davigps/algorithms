// Kadane's Algorithm
#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  int nums[n];

  for (int i = 0; i < n; i++) cin >> nums[i];

  // Initialize max so far and the current max as 0
  int max_so_far = 0;
  int current_max = 0;

  // For each element, add its value on current max and update the max so far value.
  for (int i = 0; i < n; i++) {
    current_max += nums[i];
    max_so_far = max(max_so_far, current_max);
    // Never keep current max value negative
    current_max = max(current_max, 0);
  }

  cout << "The maximum sum of a contiguous sequence is: " << max_so_far << endl;

  return 0;
}