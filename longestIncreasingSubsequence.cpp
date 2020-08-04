#include <bits/stdc++.h>
using namespace std;

#define MAXN 100100
int n, nums[MAXN], length[MAXN];

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> nums[i];
    
    int best = -1;
    for (int k = 0; k < n; k++) {
        length[k] = 1;
        for (int i = 0; i < k; i++) {
            if (nums[i] < nums[k])
                length[k] = max(length[k], length[i] + 1);
        }
        best = max(best, length[k]);
    }
    
    cout << best << endl;

    return 0;
}

