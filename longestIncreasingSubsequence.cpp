#include <bits/stdc++.h>
using namespace std;

#define MAXN 100100
int n, nums[MAXN], length[MAXN];

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> nums[i];
    
    // Initialize the best sequence length as 0
    int best = -1;
    // For each element, iterate for each element before it
    for (int k = 0; k < n; k++) {
        // Initialize its max length as 1 (the element itself)
        length[k] = 1;
        // For each element before K, if its smaller, try use its length
        for (int i = 0; i < k; i++) {
            if (nums[i] < nums[k])
                length[k] = max(length[k], length[i] + 1);
        }
        // Keep the eye on the best (maximum) answer
        best = max(best, length[k]);
    }
    
    cout << best << endl;

    return 0;
}

